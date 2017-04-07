###ExecutorAllocationManager.scala

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

    removeTimes.retain { case (executorId, expireTime) =>
      val expired = now >= expireTime
      if (expired) {
        initializing = false
        removeExecutor(executorId)
      }
      !expired
    }
  }
    