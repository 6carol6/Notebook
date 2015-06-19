备忘一下与spark相关的工作  

####调优####

[Data Storage Tips for Optimal Spark Performance](https://spark-summit.org/2015/events/data-storage-tips-for-optimal-spark-performance/)(Databricks) - spark summit'15  
Spark能够分析和存储的数据类型很多，plain text, JSON, XML, Parquet等多种数据结构都能搞定。但是能处理这些类型的文件并不是说在这些文件上都能够获得同样好的性能。
  
- Issues you’ll encounter when processing excessively large XML input files. 
- Why choose parquet files for Spark SQL? 
- How coalescing many small files may give you better performance.

[Tuning Java Garbage Collection for Spark Application](https://databricks.com/blog/2015/05/28/tuning-java-garbage-collection-for-spark-applications.html)(Intel)  
减少老年态GC的频率, G1-GC  

[Taming GC Pauses for Humongous Java Heaps in Spark Graph Computing](https://spark-summit.org/2015/events/taming-gc-pauses-for-humongous-java-heaps-in-spark-graph-computing/)(Intel) - spark summit'15  

[Accelerating Spark with RDMA for Big Data Processing: Early Experiences](http://ieeexplore.ieee.org/xpls/abs_all.jsp?arnumber=6925713&tag=1)  

[IndexedRDD: Efficient Fine-Grained Updates for RDDs](https://spark-summit.org/2015/events/indexedrdd-efficient-fine-grained-updates-for-rdds/)  
[github](https://github.com/amplab/spark-indexedrdd)  

[Accelerating Apache Spark-based Analytics on Intel Architecture](https://spark-summit.org/2015/events/accelerating-apache-spark-based-analytics-on-intel-architecture/) - spark summit'15  

[MRONLINE: MapReduce Online Performance Tuning](http://dl.acm.org/citation.cfm?id=2600229) - HPDC'14  

####性能分析####

[Making Sense of Spark Performance](https://www.usenix.org/system/files/conference/nsdi15/nsdi15-paper-ousterhout.pdf) - NSDI'15  



####应用####

[Scalable Automated Model Search](http://www.eecs.berkeley.edu/Pubs/TechRpts/2014/EECS-2014-122.pdf)  
用Spark来自动训练不同的模型从而找到最好的  
[Slide & Video](https://spark-summit.org/2014/talk/model-search-at-scale)  

[TuPAQ: An Efficient Planner for Large-scale Predictive Analytic Queries](http://arxiv.org/pdf/1502.00068v2.pdf)  

[MLlib: Machine Learning in Apache Spark](http://arxiv.org/abs/1505.06807)  

[Spark and Cassandra](https://spark-summit.org/2014/Spark+and+Cassandra)  
给Cassandra写了一个Spark的driver，让Spark能访问Cassandra数据库  
[blog](https://databricks.com/blog/2015/06/16/zen-and-the-art-of-spark-maintenance-with-cassandra.html)  

[GraphX: a resilient distributed graph system on Spark](http://dl.acm.org/citation.cfm?id=2484427)  

[Building, Debugging, and Tuning Spark Machine Learning Pipelines](https://spark-summit.org/2015/events/practical-machine-learning-pipelines-with-mllib-2/) - spark summit'2015  

[BlinkDB and G-OLA: Supporting Continuous Answers with Error Bars in SparkSQL](https://spark-summit.org/2015/events/blinkdb-ola-supporting-continuous-answers-in-sparksql/)  
[paper](http://dl.acm.org/citation.cfm?id=2735381) - SIGMOD'2015  

