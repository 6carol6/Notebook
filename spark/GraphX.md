根据GraphX的那篇[论文](http://dl.acm.org/citation.cfm?id=2484427)，主要做了以下这些优化。  

###1 Graph System Optimizations

####1.1 The GAS Decomposition
 这是一种十分适用于点分割(vertex-cut)的模型。至于什么是点分割，看图： 
 
 ![Edge-Cut and Vertex-Cut](http://i766.photobucket.com/albums/xx304/mszxw999/blog/QQ20160224101824.png)
 
容易看到点分割就是站在点的角度思考问题。这样的好处是不用有边就传输数据，只需要更新点的副本，缺点就是要同步啦。据说有工作研究过点分割的表现比边分割要好。GAS Decomposition也是这样，它就是把程序分为Gather, Apply, Scatter三个步骤。比如以下这个PageRank的程序：

```scala
def Gather(a: Double, b: Double) = a+b
def Apply(v, msgSum) {
    PR(v) = 0.15 + 0.85 * msgSum
    if(converged(PR(v))) voteToHalt(v)
}
def Scatter(v, j) = PR(v) / NumLinks(v)
```
这样做的好处是:

    The GAS decomposition leads to a pull-based model of message computation: the 
    system asks the vertex program for value of the message between adjacent vertices 
    rather than the user sending messages directly from the vertex program

因此就能够支持vertex-cut partitioning还能提高负载均衡(原文是improve work balance但是这是什么道理)，serial edge-iteration, and reduced data movement（不懂为什么啊）。但是GAS Decomposition会造成一些额外的开销，导致一些没有边的节点也会有通信。

####1.2 Graph Partitioning
这里用的方法是[2]里的方法。分为三个步骤：1) Coarsening phase; 2) Partitioning phase; 3) Uncoarsening phase.

Coarsening phase的大概思想就是每次找图的最大匹配，然后把匹配的点压缩成一个点，以此类推直到只剩ck个点，其中k是最终partition的个数，c是一个可调参数。

![](http://i766.photobucket.com/albums/xx304/mszxw999/blog/QQ20160224171010.png)

到了partitioning phase的时候，作者用了[3]中的方法。（这篇paper也是[2]的作者发的，也是参考了别人的方法）方法有三种，其中一种是从一个被压缩过的节点开始，向周围扩散直到权重等于|V|/k，以此类推。其他方法都差不多，就不多说了。

到了Uncorsening phase的时候，再把刚才的图拆开回来。

####1.3 Mirror Vertices

感觉这个有点像参数服务器(parameter server, ps)。更新好节点的数据之后发送给节点的mirror，再由mirror分发给节点的其它副本。

####1.4 Active Vertices

就是说有一些节点被合并之后就不active了，就不用再更新这些节点的数据。这样减少了不必要的数据传输和计算。

####1.5 Routing Table

Vertex Table中的一个partition对应着Routing Table中的一个partition，Routing Table指示了一个vertex会涉及到哪些Edge Table partition。

###2 Optimizations to mrTriplets

####2.1 Filtered index scanning

####2.2 Automatic join elimination

Triplet是由一个边的两个相关顶点和这个边组成的三元组，操作Triplet的map函数通常只需要访问两个邻居顶点中的一个。例如，在PageRank中，一个顶点的值的更新只与其源顶点的值有关，而与其指向目标的顶点的值无关。因此在mrTriplets的计算中，就不需要VertexRDD和EdgeRdd的3-way join，只需要2-way join。

###3 Additional Optimizations

####3.1 Memory-based shuffle

spark原生的shuffle是要写文件到本地然后传输的。这里改成了把数据直接放在内存里。当数据超时了再从内存里删掉。

####3.2 Batching and columnar structure

shuffle的时候不要一个节点一个节点传输，一次传输所有到目标机器的节点的数据。把block从row-oriented format转化成column-oriented format。还用了LZF compression压缩数据减少发送的数据量。

####3.3 Variable integer encoding

定点的ID在GraphX中表示为64位整数，但是在大多数情况下ID并没有那么长，所以在shuffle的时候会对ID进行编码成7bits的值，用最高位表示是否还需要第二个byte。这个优化使得PageRank中需要传输的数据量减少了20%。

###4 References
[1] [GraphX](http://dl.acm.org/citation.cfm?id=2484427)  
[2] [Multilevelk-way Partitioning Scheme for Irregular Graphs](http://glaros.dtc.umn.edu/gkhome/fetch/papers/mlJPDC98.pdf)  
[3] [A fast and high quality multilevel scheme for partitioning irregular graphs](http://glaros.dtc.umn.edu/gkhome/fetch/papers/mlICPP95.pdf)  
[4] [快刀初试：Spark GraphX在淘宝的实践](http://www.csdn.net/article/2014-08-07/2821097)
[5] [十分钟了解分布式计算:GraphX](http://doc.okbase.net/wei-li/archive/83118.html)