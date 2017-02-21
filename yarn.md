### Architecture

- ResourceManager(RM): 
	- 每个cluster有一个，是守护进程
	- 接收Node的心跳，维护资源的使用情况
	- 执行allocation
	- 仲裁tenants之间的竞争
	- RM是NM的全局快照
- ApplicationMaster(AM)
	- the "head" of a job
	- 管理所有的lifecycle的形势
	- 相当于一个逻辑job，向RM请求资源
- NodeManager(NM)
	- YARN中的“Worker”守护进程
	- 用于监控资源
	- 报告错误
	- 控制lifecycle(e.g., starting, killing)

### 相关工作

- Omega: 倾向于面向分布式的、多级的调度，更加关注可伸缩性(scalability)，难以保证capacity/fairness/deadlines
- Corona: 使用push based通信，和YARN的heartbeat based不同
- Mesos: 和YARN一样都有两阶段调度器。有两点不同：
	- Mesos是offer-based的，YARN是request-based的。YARN允许AM基于一些标准（例如**locations**）请求资源，允许requester基于现有的资源和使用情况改变未来的请求。
	- Mesos leverages a pool of central schedulers，而不是一个job一个intra-framework scheduler。YARN允许late binding of containers to tasks，这样每个job都能perform local optimizations