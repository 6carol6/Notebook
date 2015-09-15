##SIGCOMM2015

###1 SDN

####BwE: Flexible, Hierarchical Bandwidth Allocation for WAN Distributed Computing
@Google  

Observation: Individual flows with fixed priority may not be the ideal basis for bandwidth allocation.  
Example: It may be the highest priority for one service to receive 10Gb/s of bandwidth but upon reaching such an allocation, incremental prioirty may drop sharply favoring allocation to other serveces.  
Present a design and implementation of Bandwidth Enforcer(BwE), a global, hierarchical **bandwidth allocation infrastructure**.  

####Declarative and Expressive Approach to Control Forwarding Paths in Carrier-Grade Networks

####PGA: Using Graphs to Express and Automatically Reconcile Network Policies
@University of Wisconsin-Madison, HP Labs, Banyan, HP Networking  

现象：用SDN的人很多，创建出了各种不同的规则。导致policy abstractions and frameworks do not support natural expression and automatic composition of high-level policies from diverse sources.

