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

这个是看题目就知道讲什么的了，暂时不关心。  

###Session 3.1: Experience Track1

####Inside the Social Networks's(Datacenter) Network
@University of California, Facebook  



####Pingmesh: A Large-Scale System for Data Center Network Latency Measurement and Analysis

