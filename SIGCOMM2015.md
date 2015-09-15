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



