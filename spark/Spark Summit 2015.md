###Spark Summit 2015

####Spark Community Update

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第7个视频34:50  

####Powering Data Science with Spark

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第7个视频01:02:26  

####Spark & Hadoop at Production Scale

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第7个视频02:05:01  

####Accelerating Innovation with Spark

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第7个视频02:16:41  

####Hadoop and Spark – Perfect Together

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第7个视频02:26:50  

####A Tale of a Data-Driven Culture

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第7个视频02:38:15  

####Spark at NASA/JPL

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第7个视频02:51:43  

####Software Above the Level of a Single Device: The Implications

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第7个视频03:09:43  

####TRAINING: Intro to Apache Spark

这是一个training的lecture，稍微瞄一眼就好。（看半天才发现也是失误）

[slide](training.databricks.com/visualapi.pdf) [video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第二第三个  

Transformations and Actions

![enter image description here](http://i766.photobucket.com/albums/xx304/mszxw999/Spark/transformations%20and%20actions.png)

![enter image description here](http://i766.photobucket.com/albums/xx304/mszxw999/pairRDD%20operations.png)

#####MAP
就是RDD by RDD的转化，在转化过程中可以根据fuction做一些事情。  
['b', 'a', 'c'] -> [('b', 1), ('a', 1), ('c', 1)]  

#####FILTER
Apply user funtion: keep them if function returns true.  

#####FLATMAP
这个slide上画得好形象，去看slide  

#####GROUPBY
这个slide上画得好形象，去看slide  

（反正就是讲了一些操作，不列举了）

Discretized Stream: Fault-Tolerant Streaming Computation at Scala  

Spark SQL  

GraphX  

BlinkDB: Queries with Bounded Errors and Bounded Response Time on Very Large Data  
轮询的时候总是得到相近的结果（不完全准确），有error bar来控制  

Spark  
可以看一下首页的mailing list  

Spark和Hadoop对比
![](http://i766.photobucket.com/albums/xx304/mszxw999/Spark%20vs%20Hadoop%20MR.png)

注意看data的size node的数量 执行的时间  

#####WHY SORTING?
- Stresses "shuffle" which underpins everything from SQL to MLib
- Sorting is challenging b/c there is no reduction in data
- Sort 100TB = 500TB disk I/O and 200TB network

**Engineering Investment in Spark**
- Sort-based shuffle (SPARK-2045)
- Netty native network transport (SPARK-2468)
- External shuffle service (SPARK-3796)

**Clever Application level Techniques**
- GC and cache friendly memory layout
- Pipelining

####Deep Dive into Project Tungsten: Bringing Spark Closer to Bare Metal

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第4个视频13:03  

####Adding Complex Data to Spark Stack

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第4个视频39:30  

####Some Important Streaming Algorithms You Should Know About

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第5个视频开头（好像是接着某个视频的，然后这段视频很短，他讲完就么的了）  

####Cassandra and Spark: Optimizing for Data Locality

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第6个视频开头（Q&A）  

####BlinkDB and G-OLA: Supporting Continuous Answers with Error Bars in SparkSQL

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第6个视频19:24  
 
####Towards the True Elasticity of Spark
 
[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第6个视频57:49  

####Spark on Mesos – A Deep Dive

[video](http://livestream.com/accounts/8038169/sparksummit2015-tracka) - 第6个视频01:27:58  
