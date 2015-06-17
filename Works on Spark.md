备忘一下与spark相关的工作  

###调优###

[Tuning Java Garbage Collection for Spark Application](https://databricks.com/blog/2015/05/28/tuning-java-garbage-collection-for-spark-applications.html)  
减少老年态GC的频率, G1-GC  

[Accelerating Spark with RDMA for Big Data Processing: Early Experiences](http://ieeexplore.ieee.org/xpls/abs_all.jsp?arnumber=6925713&tag=1)

###应用###

[Scalable Automated Model Search](http://www.eecs.berkeley.edu/Pubs/TechRpts/2014/EECS-2014-122.pdf)  
用Spark来自动训练不同的模型从而找到最好的  
[Slide & Video](https://spark-summit.org/2014/talk/model-search-at-scale)  

[TuPAQ: An Efficient Planner for Large-scale Predictive Analytic Queries](http://arxiv.org/pdf/1502.00068v2.pdf)  

[Spark and Cassandra](https://spark-summit.org/2014/Spark+and+Cassandra)  
给Cassandra写了一个Spark的driver，让Spark能访问Cassandra数据库  

[GraphX: a resilient distributed graph system on Spark](http://dl.acm.org/citation.cfm?id=2484427)


