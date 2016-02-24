根据GraphX的那篇[论文](http://dl.acm.org/citation.cfm?id=2484427)，主要做了以下这些优化。  

####Graph System Optimizations

- **The GAS Decomposition**: 一般的vertex programs都可以被分成Gather, Apply, Scatter三个步骤。比如以下这个PageRank的程序：

```scala
def Gather(a: Double, b: Double) = a+b
def Apply(v, msgSum) {
    PR(v) = 0.15 + 0.85 * msgSum
    if(converged(PR(v))) voteToHalt(v)
}
def Scatter(v, j) = PR(v) / NumLinks(v)
```


####Optimizations to mrTriplets

####Additional Optimizations