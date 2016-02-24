根据GraphX的那篇[论文](http://dl.acm.org/citation.cfm?id=2484427)，主要做了以下这些优化。  

###1 Graph System Optimizations

####1.1 The GAS Decomposition
 一般的vertex programs都可以被分成Gather, Apply, Scatter三个步骤。比如以下这个PageRank的程序：

```scala
def Gather(a: Double, b: Double) = a+b
def Apply(v, msgSum) {
    PR(v) = 0.15 + 0.85 * msgSum
    if(converged(PR(v))) voteToHalt(v)
}
def Scatter(v, j) = PR(v) / NumLinks(v)
```
这样做的好处是:

    The GAS decomposition leads to a pull-based model of message computation: the system asks the vertex program for 
    value of the message between adjacent vertices rather than the user sending messages directly from the vertex program

因此就能够支持vertex-cut partitioning还能提高负载均衡(原文是improve work balance但是这是什么道理)，serial edge-iteration, and reduced data movement（不懂为什么啊）。vertex-cut就是把点切开为两个副本保留，好处是不用有边就传输数据，只需要更新点的副本，缺点就是要同步啦。如图所示：
![Edge-Cut and Vertex-Cut](http://i766.photobucket.com/albums/xx304/mszxw999/blog/QQ20160224101824.png)

不过在之前的工作里有说大部分的情况用vertex-cut都表现得比edge-cut好呢。

但是GAS Decomposition会造成一些额外的开销，导致一些没有边的节点也会有通信。

####1.2 Graph Partitioning
这里用的方法是[2]里的方法。大概思想就是每次找图的最大匹配，然后把匹配的点压缩成一个点，以此类推直到只剩ck个点，其中k是最终partition的个数，c是一个可调参数。

![](http://i766.photobucket.com/albums/xx304/mszxw999/blog/QQ20160224171010.png)

到了partition的时候，作者用了[3]中的方法。（这篇paper也是[2]的作者发的，是厉害啊）

####1.3 Mirror Vertices

感觉这个有点像参数服务器(parameter server, ps)。更新好节点的数据之后发送给节点的mirror，再由mirror分发给节点的其它副本。

####1.4 Active Vertices

就是说有一些节点被合并之后就不active了，就不用再更新这些节点的数据。这样减少了不必要的数据传输和计算。

###2 Optimizations to mrTriplets

###3 Additional Optimizations

###4 References
[1] [GraphX](http://dl.acm.org/citation.cfm?id=2484427)  
[2] [Multilevelk-way Partitioning Scheme for Irregular Graphs](http://glaros.dtc.umn.edu/gkhome/fetch/papers/mlJPDC98.pdf)  
[3] [A fast and high quality multilevel scheme for partitioning irregular graphs](http://glaros.dtc.umn.edu/gkhome/fetch/papers/mlICPP95.pdf)