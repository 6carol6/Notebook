代码版本：mesos-1.1.0 和 spark-2.0.0


### spark的MesosSchedulerUtil.scala

首先要生成一个`MesosSchedulerDriver`用于跟Mesos交流。在Framework（这里是Spark）的MesosSchedulerUtil.scala里会生成`FrameworkInfo`传给新建的`MesosSchedulerDriver`

### mesos-1.1.0/include/mesos/v1/mesos.proto

这里面有`FrameworkInfo`的定义：

```
/**
 * Describes a framework.
 */
message FrameworkInfo {
  // Used to determine the Unix user that an executor or task should be
  // launched as.
  //
  // When using the MesosSchedulerDriver, if the field is set to an
  // empty string, it will automagically set it to the current user.
  //
  // When using the HTTP Scheduler API, the user has to be set
  // explicitly.
  required string user = 1;

  // Name of the framework that shows up in the Mesos Web UI.
  required string name = 2;

  // Note that 'id' is only available after a framework has
  // registered, however, it is included here in order to facilitate
  // scheduler failover (i.e., if it is set then the
  // MesosSchedulerDriver expects the scheduler is performing
  // failover).
  optional FrameworkID id = 3;

  // The amount of time (in seconds) that the master will wait for the
  // scheduler to failover before it tears down the framework by
  // killing all its tasks/executors. This should be non-zero if a
  // framework expects to reconnect after a failure and not lose its
  // tasks/executors.
  //
  // NOTE: To avoid accidental destruction of tasks, production
  // frameworks typically set this to a large value (e.g., 1 week).
  optional double failover_timeout = 4 [default = 0.0];

  // If set, agents running tasks started by this framework will write
  // the framework pid, executor pids and status updates to disk. If
  // the agent exits (e.g., due to a crash or as part of upgrading
  // Mesos), this checkpointed data allows the restarted agent to
  // reconnect to executors that were started by the old instance of
  // the agent. Enabling checkpointing improves fault tolerance, at
  // the cost of a (usually small) increase in disk I/O.
  optional bool checkpoint = 5 [default = false];

  // Used to group frameworks for allocation decisions, depending on
  // the allocation policy being used.
  optional string role = 6 [default = "*"];

  // Used to indicate the current host from which the scheduler is
  // registered in the Mesos Web UI. If set to an empty string Mesos
  // will automagically set it to the current hostname if one is
  // available.
  optional string hostname = 7;

  // This field should match the credential's principal the framework
  // uses for authentication. This field is used for framework API
  // rate limiting and dynamic reservations. It should be set even
  // if authentication is not enabled if these features are desired.
  optional string principal = 8;

  // This field allows a framework to advertise its web UI, so that
  // the Mesos web UI can link to it. It is expected to be a full URL,
  // for example http://my-scheduler.example.com:8080/.
  optional string webui_url = 9;

  message Capability {
    enum Type {
      // This must be the first enum value in this list, to
      // ensure that if 'type' is not set, the default value
      // is UNKNOWN. This enables enum values to be added
      // in a backwards-compatible way. See: MESOS-4997.
      UNKNOWN = 0;

      // Receive offers with revocable resources. See 'Resource'
      // message for details.
      REVOCABLE_RESOURCES = 1;

      // Receive the TASK_KILLING TaskState when a task is being
      // killed by an executor. The executor will examine this
      // capability to determine whether it can send TASK_KILLING.
      TASK_KILLING_STATE = 2;

      // Indicates whether the framework is aware of GPU resources.
      // Frameworks that are aware of GPU resources are expected to
      // avoid placing non-GPU workloads on GPU agents, in order
      // to avoid occupying a GPU agent and preventing GPU workloads
      // from running! Currently, if a framework is unaware of GPU
      // resources, it will not be offered *any* of the resources on
      // an agent with GPUs. This restriction is in place because we
      // do not have a revocation mechanism that ensures GPU workloads
      // can evict GPU agent occupants if necessary.
      //
      // TODO(bmahler): As we add revocation we can relax the
      // restriction here. See MESOS-5634 for more information.
      GPU_RESOURCES = 3;

      // Receive offers with resources that are shared.
      SHARED_RESOURCES = 4;

      // Indicates that (1) the framework is prepared to handle the
      // following TaskStates: TASK_UNREACHABLE, TASK_DROPPED,
      // TASK_GONE, TASK_GONE_BY_OPERATOR, and TASK_UNKNOWN, and (2)
      // the framework will assume responsibility for managing
      // partitioned tasks that reregister with the master.
      //
      // Frameworks that enable this capability can define how they
      // would like to handle partitioned tasks. Frameworks will
      // receive TASK_UNREACHABLE for tasks on agents that are
      // partitioned from the master. If/when a partitioned agent
      // reregisters, tasks on the agent that were started by
      // PARTITION_AWARE frameworks will not killed.
      //
      // Without this capability, frameworks will receive TASK_LOST
      // for tasks on partitioned agents; such tasks will be killed by
      // Mesos when the agent reregisters (unless the master has
      // failed over).
      PARTITION_AWARE = 5;
    }

    // Enum fields should be optional, see: MESOS-4997.
    optional Type type = 1;
  }

  // This field allows a framework to advertise its set of
  // capabilities (e.g., ability to receive offers for revocable
  // resources).
  repeated Capability capabilities = 10;

  // Labels are free-form key value pairs supplied by the framework
  // scheduler (e.g., to describe additional functionality offered by
  // the framework). These labels are not interpreted by Mesos itself.
  // Labels should not contain duplicate key-value pairs.
  optional Labels labels = 11;
}

```