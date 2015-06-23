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

####Large-Scale Lasso and Elastic-Net Regularized Generalized Linear Models

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第1个视频18:30  

####Dynamic Community Detection for Large-scale e-Commerce data with Spark Streaming and GraphX

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第1个视频47:48  

####Digital Attribution Modeling Using Apache Spark

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第1个视频1:13:03  

####Building, Debugging, and Tuning Spark Machine Learning Pipelines

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第1个视频2:16:00  

####IndexedRDD: Efficient Fine-Grained Updates for RDDs

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第1个视频2:48:00  

####Healthcare Predictive Analytics within the OR

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第1个视频3:18:00  

####Deconstructing Recommendations on Spark
How I learned to stop worrying and love the shuffle  
[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第1个视频3:57:50  

####Flyby: Improved Dense Matrix Multiplication

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第1个视频4:17:20  

####Extending Word2Vec for Performance and Semi-Supervised Learning

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第1个视频4:44:20  

####TRAINING: DevOps with Apache Spark Workshop (Advanced)

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第2个视频42:36+第4个视频+第5个视频29:30+第6个视频  

####Large-Scale Lasso and Elastic-Net Regularized Generalized Linear Models

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第3个视频开头（只有1分钟左右，所以我并不确定这是哪段视频）  

####SparkR: The Past, the Present and the Future

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第3个视频2:51  

####Data Storage Tips for Optimal Spark Performance

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第3个视34:30  

(trackerB第7个视频和第1个重复了)

trackerC的第1个视频是圆桌问答之类的  

####TRAINING: Data Science with Apache Spark (Advanced)

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第2个视39:49（5hours）  

####Automated Machine Learning Using Spark Mllib to Improve Customer Experience

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第3个视04:15  

####Solving Low Latency Query Over Big Data with Spark SQL

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第3个视30:12  

####A Big Data Lake Based on Spark for BBVA Bank

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第3个视01:02:40  

####Sqoop on Spark for Data Ingestion

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第3个视01:22:05  

(第4个视频打不开)

####Use of Spark MLlib for Predicting the Offlining of Digital Media

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视09:09  

####Spark and Spark Streaming at Netflix

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视37:48  

####Lessons Learned with Spark at the US Patent & Trademark Office

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视1:13:02  

####Appraiser : How Airbnb Generates Complex Models in Spark for Demand Prediction

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视2:08:22  

####Integrating Spark and Solr

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视2:42:00  

####Diagnosing Open-Source Community Health with Spark

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视3:15:30  

####Building a Data Warehouse for Business Analytics using Spark SQL

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视3:40:12  

####Towards Benchmarking Modern Distributed Streaming Systems

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视4:10:36  

####Migrating Complex Data Aggregation from Hadoop to Spark

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视4:40:32  

####The Little Warehouse That Couldn’t, Or: How We Learned to Stop Worrying and Move to Spark

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视4:59:26  


