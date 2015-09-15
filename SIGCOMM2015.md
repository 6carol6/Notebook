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
Tackle the open problem of automatic. correct and fast composition of multiple independently specified network policies.  

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

###Session 5: Wireless

这个不看。  

###Session 6: CDN and wide area infrastructure

这个不看。  

###Session 7.1: Scheduling and resource management

####Hopper: Decentralized Speculation-aware Cluster Scheduling at Scale



####Silo: Predictable Message Latency in the Cloud

###Session 7.2: Scheduling and resource management

####Network-Aware Scheduling for Data-Parallel Jobs: Plan When You Can