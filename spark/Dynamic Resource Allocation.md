### ExecutorAllocationManager.scala

在`SparkContext`里会调用这个类的`start()`

```
/**
    * Register for scheduler callbacks to decide when to add and remove executors, and start
    * the scheduling task.
    */
    def start(): Unit = {
        listenerBus.addListener(listener)

        val scheduleTask = new Runnable() {
            override def run(): Unit = {
                try {
                    schedule()
                } catch {
                case ct: ControlThrowable =>
                    throw ct
                case t: Throwable =>
                    logWarning(s"Uncaught exception in thread ${Thread.currentThread().getName}", t)
                }
            }
        }
        executor.scheduleAtFixedRate(scheduleTask, 0, intervalMillis, TimeUnit.MILLISECONDS)

        client.requestTotalExecutors(numExecutorsTarget, localityAwareTasks, hostToLocalTaskCount)
    }
```

`schedule()`在这里


```  
/**
   * This is called at a fixed interval to regulate the number of pending executor requests
   * and number of executors running.
   *
   * First, adjust our requested executors based on the add time and our current needs.
   * Then, if the remove time for an existing executor has expired, kill the executor.
   *
   * This is factored out into its own method for testing.
   */
  private def schedule(): Unit = synchronized {
    val now = clock.getTimeMillis

    updateAndSyncNumExecutorsTarget(now)

    // 这里的removeTimes是一个HashMap[String, Long]（<ExecutorId, expireTime>）
    // 超时未被占用，移除Executor
    removeTimes.retain { case (executorId, expireTime) =>
      val expired = now >= expireTime
      if (expired) {
        initializing = false
        removeExecutor(executorId)
      }
      !expired
    }
  }
```

`updateAndSyncNumExecutorsTarget(now)`里调用`addExecutors()`，这里是每次翻倍申请Executor的地方。

然后回到最上面的`start()`，有一个`Runnable()`什么时候`run()`呢，可以看到这个`Runnable()`被传入了`executor.scheduleAtFixedRate(scheduleTask, 0, intervalMillis, TimeUnit.MILLISECONDS)`。这里的`executor`的定义如下：

```
  // Executor that handles the scheduling task.
  private val executor =
    ThreadUtils.newDaemonSingleThreadScheduledExecutor("spark-dynamic-executor-allocation")
```

> ### util/ThreadUtils.scala
> 
> ```
>   /**
>    * Wrapper over newSingleThreadExecutor.
>    */
>   def newDaemonSingleThreadExecutor(threadName: String): ExecutorService = {
>     val threadFactory = new ThreadFactoryBuilder().setDaemon(true).setNameFormat(threadName).build()
>     Executors.newSingleThreadExecutor(threadFactory)
>   }
> ```
> 
> 这应该是一个工厂模式，返回了一个`ExecutorService`。所以`executor.scheduleAtFixedRate(scheduleTask, 0, intervalMillis, TimeUnit.MILLISECONDS)`应该可以被理解为每隔`intervalMillis`时间就被调用一下啦。

```
  // Polling loop interval (ms)
  private val intervalMillis: Long = 100
```

这个时间间隔被定义为了100ms。

我们现在知道了申请Executor的函数会每隔100ms被调用一次，那么这个函数做了什么呢？

如果还有task在排队，并且还没有被调度，就要`addExecutors(maxNeeded)`，这里的`maxNeeded`取(task的总个数/每个task需要的Executor的个数)上取整。

先看一些默认值表示什么意思，值是多少。

```
  // Lower and upper bounds on the number of executors.
  //最小的Executor数量，默认为0
  private val minNumExecutors = conf.get(DYN_ALLOCATION_MIN_EXECUTORS) 
  //最大的Executor数量，默认为Int.MaxValue
  private val maxNumExecutors = conf.get(DYN_ALLOCATION_MAX_EXECUTORS) 
  //初始请求Executor数量，为max{DYN_ALLOCATION_MIN_EXECUTORS，DYN_ALLOCATION_INITIAL_EXECUTORS(默认为DYN_ALLOCATION_MIN_EXECUTORS)，EXECUTOR_INSTANCES(默认为0)}
  private val initialNumExecutors = Utils.getDynamicAllocationInitialExecutors(conf) 

  // The desired number of executors at this moment in time. If all our executors were to die, this
  // is the number of executors we would immediately want from the cluster manager.
  private var numExecutorsTarget = initialNumExecutors

  // Number of executors to add in the next round
  private var numExecutorsToAdd = 1
```

> ### internal/package.scala
> 
> ```
>   private[spark] val DYN_ALLOCATION_MIN_EXECUTORS =
>    ConfigBuilder("spark.dynamicAllocation.minExecutors").intConf.createWithDefault(0)
>   private[spark] val DYN_ALLOCATION_MAX_EXECUTORS =
>    ConfigBuilder("spark.dynamicAllocation.maxExecutors").intConf.createWithDefault(Int.MaxValue)
>   private[spark] val DYN_ALLOCATION_INITIAL_EXECUTORS =
>    ConfigBuilder("spark.dynamicAllocation.initialExecutors")
>      .fallbackConf(DYN_ALLOCATION_MIN_EXECUTORS)
> ```
> 
> ### util/Utils.scala
> 
> ```
>   /**
>   * Return the initial number of executors for dynamic allocation.
>   */
>  def getDynamicAllocationInitialExecutors(conf: SparkConf): Int = {
>    if (conf.get(DYN_ALLOCATION_INITIAL_EXECUTORS) < conf.get(DYN_ALLOCATION_MIN_EXECUTORS)) {
>      logWarning(s"${DYN_ALLOCATION_INITIAL_EXECUTORS.key} less than " +
>        s"${DYN_ALLOCATION_MIN_EXECUTORS.key} is invalid, ignoring its setting, " +
>          "please update your configs.")
>    }
>
>    if (conf.get(EXECUTOR_INSTANCES).getOrElse(0) < conf.get(DYN_ALLOCATION_MIN_EXECUTORS)) {
>      logWarning(s"${EXECUTOR_INSTANCES.key} less than " +
>        s"${DYN_ALLOCATION_MIN_EXECUTORS.key} is invalid, ignoring its setting, " +
>          "please update your configs.")
>    }
>
>    val initialExecutors = Seq(
>      conf.get(DYN_ALLOCATION_MIN_EXECUTORS),
>      conf.get(DYN_ALLOCATION_INITIAL_EXECUTORS),
>      conf.get(EXECUTOR_INSTANCES).getOrElse(0)).max
>
>    logInfo(s"Using initial executors = $initialExecutors, max of " +
>      s"${DYN_ALLOCATION_INITIAL_EXECUTORS.key}, ${DYN_ALLOCATION_MIN_EXECUTORS.key} and " +
>        s"${EXECUTOR_INSTANCES.key}")
>    initialExecutors
>  }
> ```
>

```
  /**
   * Request a number of executors from the cluster manager.
   * If the cap on the number of executors is reached, give up and reset the
   * number of executors to add next round instead of continuing to double it.
   *
   * @param maxNumExecutorsNeeded the maximum number of executors all currently running or pending
   *                              tasks could fill
   * @return the number of additional executors actually requested.
   */
  // 这里的参数maxNumExecutorNeeded = ceil(pending的task个数/每个task需要的Executor个数)
  private def addExecutors(maxNumExecutorsNeeded: Int): Int = {
    // Do not request more executors if it would put our target over the upper bound
    if (numExecutorsTarget >= maxNumExecutors) {
      logDebug(s"Not adding executors because our current target total " +
        s"is already $numExecutorsTarget (limit $maxNumExecutors)")
      numExecutorsToAdd = 1
      return 0
    }

    val oldNumExecutorsTarget = numExecutorsTarget
    // There's no point in wasting time ramping up to the number of executors we already have, so
    // make sure our target is at least as much as our current allocation:
    numExecutorsTarget = math.max(numExecutorsTarget, executorIds.size)
    // Boost our target with the number to add for this round:
    numExecutorsTarget += numExecutorsToAdd
    // Ensure that our target doesn't exceed what we need at the present moment:
    // 保证请求不会超过现在pending的task所需要的Executor的个数
    numExecutorsTarget = math.min(numExecutorsTarget, maxNumExecutorsNeeded)
    // Ensure that our target fits within configured bounds:
    // 保证不会超过设置最大的个数，不会小于设置最小的个数
    numExecutorsTarget = math.max(math.min(numExecutorsTarget, maxNumExecutors), minNumExecutors)

    // 现在需要的和上一把需要的差值（这一把多加了numExecutorsToAdd），
    // 也就是这一把需要多申请delta个Executor
    val delta = numExecutorsTarget - oldNumExecutorsTarget

    // If our target has not changed, do not send a message
    // to the cluster manager and reset our exponential growth
    if (delta == 0) {
      numExecutorsToAdd = 1
      return 0
    }

    // 这里的client是SparkContext.this
    val addRequestAcknowledged = testing ||
      client.requestTotalExecutors(numExecutorsTarget, localityAwareTasks, hostToLocalTaskCount)
    if (addRequestAcknowledged) {
      val executorsString = "executor" + { if (delta > 1) "s" else "" }
      logInfo(s"Requesting $delta new $executorsString because tasks are backlogged" +
        s" (new desired total will be $numExecutorsTarget)")
      numExecutorsToAdd = if (delta == numExecutorsToAdd) {
        numExecutorsToAdd * 2
      } else {
        1
      }
      delta
    } else {
      logWarning(
        s"Unable to reach the cluster manager to request $numExecutorsTarget total executors!")
      numExecutorsTarget = oldNumExecutorsTarget
      0
    }
  }
```

> SparkContext.scala