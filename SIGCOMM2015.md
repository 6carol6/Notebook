##SIGCOMM2015

###Session 1: SDN

####BwE: Flexible, Hierarchical Bandwidth Allocation for WAN Distributed Computing
@Google  

Observation: Individual flows with fixed priority may not be the ideal basis for bandwidth allocation.  
Example: It may be the highest priority for one service to receive 10Gb/s of bandwidth but upon reaching such an allocation, incremental prioirty may drop sharply favoring allocation to other serveces.  
Present a design and implementation of Bandwidth Enforcer(BwE), a global, hierarchical **bandwidth allocation infrastructure**.  

####A Declarative and Expressive Approach to Control Forwarding Paths in Carrier-Grade Networks
@Universite catholique de Louvain, Cisco Systems, IMDEA Networks Institute  

####PGA: Using Graphs to Express and Automatically Reconcile Network Policies
@University of Wisconsin-Madison, HP Labs, Banyan, HP Networking  

现象：用SDN的人很多，创建出了各种不同的规则。导致policy abstractions and frameworks do not support natural expression and automatic composition of high-level policies from diverse sources.  
Tackle the open problem of automatic, correct and fast composition of multiple independently specified network policies.  

####Central Control Over Distributed Routing
@Universite catholique de Louvain, ETH Zurich, Princeton University  

Centralizing routing decisions offers tremendous flexibility, but sacrifices to robustness of distributed protocols.  
We present *Fibbing*, an architecture that achieves both flexibility and robustness trough central control over distributed routing.  

###Session 2: Network Algorithmics and Economics

####Poptrie: A Compressed Trie with Population Count for Fast and Scalable Software IP Routing Table Lookup
@The University of Tokyo, NTT Communications Corporation  

Internet of Things leads to routing table explosion.   
We contribute by a **fast and scalable software routing lookup algorithm** based on a multiway trie, called *Poptrie*.  

####How to Bid the Cloud
@Princeton University, National University of Sigapore, City University of Hong Kong  

给云定价。这个是看题目就知道讲什么的了，暂时不关心。  

###Session 3.1: Experience Track1

####Inside the Social Networks's(Datacenter) Network
@University of California, Facebook  

####Pingmesh: A Large-Scale System for Data Center Network Latency Measurement and Analysis

###Session 3.2: Experience Track2

####Large-scale measurements of wireless network behavior

wireless的先不看  

####End-User Mapping: Next Generation Request Routing for Content Delivery

@Akamai  

内容分发网络(**Content Delivery Networks, CDNs**)能够使得用户请求到比较近的数据。这个时候需要用户能够使用DNS协议路由到比较近的服务器请求数据。  

####Jupiter Rising: A Decade of Clos Topologies and Centralized Control in Google's Datacenter Network
@Google  

Google share经验的文章。  
We present our approach for overcoming the cost, operational complexity, and limited scale endemic to datacenter networks a decade ago.  
Three themes unify the five generations of datacenter networks detailed in this paper.  

1. Multi-stage Clos topologies built from commodity switch silicon can support cost-effective deployment of building-scale networks.
2. Much of the general, but complex, decentralized network routing and management protocols supporting arbitrary deployment scenarios were overkill for single-operator, pre-planned datacenter networks. We built a **centralized control mechanism** based on a global configuration pushed to all datacenter switches.  
3. Modular hardware design coupled with simple, robust software allowed our design to also support inter-cluster and wide-area networks.

###Session 4: Middleboxes

####multi-context TLS(mcTLS): Enabling Secure In-Network Functionality in TLS
@CMU, Case Western Reserve University, Telefonica Research  

Problem: *Transport Layer Security(TLS)*, the standard protocol for encryption in the Internet, assumes that all functionality resides at the endpoints, making it impossible to use in-network services that optimize network resource usage, improve user experience, and protect clients and servers from security threats.  
Solution: Introduce multi-context TLS, which extends TLS to support middleboxes. Allowing endpoints and content providers to explicitly introduce middleboxes in secure end-top-end sessions while controlling which part of the data they can read or write.  
大概就是说加密之后middlebox啊什么的就不能对数据进行处理了，只有endpoint才能接触到数据，这个很烦。然后解决方法就是数据的来源和endpoint可以规定哪部分数据是middlebox可读可写的。  

####BlindBox: Deep Packet Inspection over Encrypted Traffic
@UC Berkeley  

跟上一篇文章的功能差不多，都是要让middlebox可以处理加密的数据。嗯，就是跟加密算法有千丝万缕的联系。  

####Rollback Recovery for Middleboxes
@UC Berkeley, University of Washington, Intel Research, NEC Labs, University of Pisa, ICSI  

No existing middlebox design provides failover that is **correct, fast to recover, and imposes little increased latency on failure-free operations**.  
We present a new design for fault-tolerance in middleboxes that achieves these three goals.  

####Scaling Up Clustered Network Appliances with ScaleBricks
@CMU, Intel Labs, Harvard University, Connectem Inc.  

Apply a compact lookup structure to route packets directly to the appropriate handling node, without incurring the cost of multiple hops across the internal interconnect.   
用了一种神奇的方法让数据包直达handling node  

###Session 5: Wireless

这个不看。  

###Session 6: CDN and wide area infrastructure

####Practical, Real-time Centralized Control for CDN-based Live Video Delivery

@CMU, KAIST, Conviva Inc.  

Live video delivery is expected to reach a peak of 50 Tbps this year.->真的么，吓哭了。This surging popularity is fundamentally changing the Internet video delivery landscape. CDNs must meet users' demands for fast join times, high bitrates, and low buffering ratios, and low buffering ratios, while minimizing their own cost of delivery and responding to issues in real-time. Wide-area latency, loss, and failures, as well as varied workloads ("meage-events" to long-tail), make meeting these demands challenging.  

An analysis of video sessions concluded that a centralized controller could improve user experience, but CDN systems have shied away from such designs due to the difficulty of quickly handling failures, a requirement of both operators and users. **We introduce VDN, a centralized algorithm for live video optimization.** VDN provides CDN operators with real-time, fine-grained control.  

####A Control-Theoretic Approach for Dynamic Adaptive Video Streaming over HTTP

@CMU  

对video application做用户可察觉的QoS是非常重要的，而网络对这个的支持比较少，所以处处是瓶颈。因此，一个客户端比特率自适应的算法对用户体验是很重要的。之前的工作告诉我们了一些目前最好的商用解决方案的限制。  

- 客户端的比特自适应逻辑能有多好？（比特率估计vs缓存占用）
- How well specific classes of approaches will perform under diverse operating regimes (e.g., high throughput variability)
- 实际上如何平衡不同的QoE目标？（startup delay vs. rebuffering）。

1. To bring some rigor to this space, we deploy a principled control-theoretic model to reason about a broad spectrum of strategies.
2. We propose a novel *model predictive control* algorithm that can optimally combine throughput and buffer occupancy information to outperform traditional approaches.
3. We present a practical implementation in a reference video player to validate our approach using realistic trace-driven emulations.

###Session 7.1: Scheduling and resource management

####Hopper: Decentralized Speculation-aware Cluster Scheduling at Scale

@California Institute of Technology, Microsoft Research, University of Southern California  

集群的size和复杂度变得越来越大了，providing scalable and predictable performance is an increasingly important challenge. 获得predictable performance的一个关键的障碍就是stragglers（就是那些比预想花费更长时间完成的任务）。面对stragglers，现有的最好的解决方案就是*speculation*，也就是随机选择多个copy执行，然后选择运行最快的那个结果。In this work, we present **Hopper**, a job scheduler that is speculation-aware, i.e., that integrates the tradeoffs associated with speculation into job scheduling decisions.  

####Silo: Predictable Message Latency in the Cloud

###Session 7.2: Scheduling and resource management

####Network-Aware Scheduling for Data-Parallel Jobs: Plan When You Can

####Low Latency Geo-distributed Data Analytics

####Efficient Coflow Scheduling Without Prior Knowledge

###Session8: Data center networking

####Condor: Better Topologies through Declarative Design

####Presto: Edge-based Load Balancing for Fast Datacenter Networks

####Packet-Level Telemetry in Large Datacenter Networks

####Enabling End-Host Network Functions

###Session 9: Congestion control and transport protocols

####Adaptive Congestion Control for Unpredictable Cellular Networks

####Congestion Control for Large-Scale RDMA deployments

####TIMELY: RTT-based Congestion Control for the Datacenter

####R2C2: A Network Stack or Rack-scale Computers

###Session 10: Wide area networks and traffic

####InterTubes: A Study of the US Long-haul Fiber-optic Infrastructure

####Spatiotemporal Traffic Matrix Synthesis

###Session 11: Security, Privacy and Censorship

这个也不看啦~