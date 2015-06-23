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

**Spark and Hadoop - How Can We Do Better**  

- Resource Management
	- YARN for multi-tenant, diverse worklods with predictable SLAs
- Tiered Memory Storage
	- HDFS in-memory tier - External BlockStore for RDD Cache
- SparkSQL & Hive for SQL
	- Interop with modern Metastore/HS2, optimized ORC support, advanced analytics e.g. Geospatial
- Spark & NoSQL
	- Deep integration with HBase via DataSources/Catalyst for Predicate/Aggregate Pushdown
- Connect The Dots - Algorithms to Use-Cases
	- Higher-level ML Absractions - E.g. OneVsRest Validation, Tuning, Pipline assembly, Model export/retraing ...
- Ease of Use
	- Apache Zeppelin for interactive notebooks
- Matadata & Governance
	- Apache Atlas for metadata & Apache Falcon fupport for Spark pipeline
- Security & Operations
	- Apache Ranger managed authorization and deployment/management via Apache Ambari
- Deployable Anywhere
	- Linux, Windows, on-premises or cloud
- Self-Service Spark in the Cloud
	- Easy launch of Data Science clusters via Cloudbreak and Ambari - for Azure, AWS, GCP, OpenStack, Docker

**Real World Use Case**  

- Real-time, Predictive App
- Datascience
- ML:Spark SQL:Hive NoSQL:HBase Stream

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

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackb) - 第1个视频2:48:00 [github](https://github.com/amplab/spark-indexedrdd)  

**Tradeoff**
  
- Immutability
	- fault tolerance
	- straggler mitigation
	- dataset reusability
	- parallel recovery
- Fine-grained updates
	- streaming
	- aggregation
	- incremental algorithms

Can we have both? Yes, we have IndexedRDD now.  

原有的RDD的每一个partition都是一个Array，IndexedRDD的每一个partition都是一个Persistent Adaptive Radix Tree(PART)  

**Radix Tree**

- Sorted order traversals (ulike hash tables)
- Better asymptotic performance than binary search trees for long keys (O(k) vs O(klogn))
- Very efficient union and intersection operations
- Predictable performance: no rehashing or rebalancing

**Limitations**

- GC pauses
	- Future work: Off-heap storage w/ reference counting
- Scan performance
	- Future work: Layout-aware allocator

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

**Goal: Understand the Best Practices for Storing and Working with Data in files with Spark**  

#####Basic Data Storage Decisions  

- File Size
	- Too Small: Lots of time opening file handles
	- Too Big: Files need to be splittable
	- Optimize for your File System
	- Good Rule of Thumb: 64MB - 1GB
- Choosing a Compression Format
	- The Obvious
		- Minimize the Compressed Size of Files
		- Decoding characteristics
	- Pay attention to Splittable vs. NonSplittable
	- Common Compression Formats for Big Data
		- Splittable:gzip, Snappy, bzip2, LZO, and LZ4 
		- Columnar formats for Structured Data - Parquet

#####Data Format Best Practices

**Plain Text**  

- sc.textFile() splits the file into lines
	- So keep your lines a reasonable size. (如果只有1行，那么会比较麻烦)
	- Or use a different method to read data in.
- Keep file sizes < 1GB if compressed with a non-splittable format

**Basic Structured Text Tiles**  

- Use Spark transformations to ETL the data
- Optionally use Spark SQL for analysizing
- Includes CSV, JSON, XML

- CSV
	- Use the relatively new Spark-CSV package
	- Spark SQL Malformed Data Tip:
		- Use a where clause and sanity check fields

- JSON
	- Ideally have one JSON object per line
		- Otherwith, DIY parsing the JSON
	- Prefer specifying a schema over inferSchema
	- Watch out for arbitrary number of keys
		- Inferring Schema will result in an executor OOM error
	- Spark SQL Malformed Data Tip:
		- Bad inputs have a column called_corrupt record and other columns will be null.
	
- XML
	- Not an ideal Big Data Format
		- Typically not one XML object per line
		- So you'll need to DIY parse
	- Not a lot of built in library support for XML
	- Watch out for very large compressed files
	- May need to employ the General Tips to parse

**Data Interchange Formats with a Schema**

- Good Practice to enforce an API with backward
	- Avro, Parquet, and Thrift are common ones
- Usually, good compression
- Data format itself is not corrupt
	- But underlying records still be

- Avro
	- Use DataFile Writer to write multiple objects
	- Use spark-avro package to read in
	- Don't transfer "AvroKey" across driver and workers
		- AvroKey is not serializable
		- Pull out fields of interest or convert to JSON

- Protocol Buffers
	- Need to figure out how to encode multiple in a file
		- Encode in Sequence Files or other similar file format
		- Prepend the number of bytes before reading the next message
		- Base64 encode one per line
	- Currently, no built in Spark package to support
		- Opportunity to contribute to open source community
		- For now, convert to JSON and read into Spark SQL

- Columnar Formats: Parquet & ORD
	- Greate for use with Spark SQL
		- Parquet is actually best practice for Spark SQL
	- Makes it easy to pull only certain records at a time
	- Worth time to encode if multiple passes on data
	- Do not support appending one record at a time
		- Not good for collecting log records

#####General Tips

**Reuse Hadoop Libraries**  

- HadoopRDD & NewHadoopRDD
	- Reuse Hadoop File format libraries
- Hive SerDe's are support in Spark SQL
	- Load your SerDe jar onto your Spark Cluster
	- Issue a SHOW CREATE TABLE command
	- Enterr the create table command (with EXTERNAL)

**Controlling the Output File Size**  

- Spark generally writes one file per partition
- Use coalesce to write out less files
- Use repartition to write out more files
	- This will cause a shuffle of the data
- If repartition is too expensive
	- Call mapPartition to get an iterator and write out as many (or few) files as you would like

**sc.wholeTextFiles()**  

- The whole file should fit into memory
- Good for file formats that aren't splittable by line
	- Such as XML file
- Will need to performance tune 可能有些慢

**Use “filename” as the RDD element**  

- filenames = sc.parallelize(["s3:/file1", "s3:/file2,..."])
- Allows you to function on a single file
	- filenames.map(...call_function_on_filename)
- Use to decode non-standard compression formats
- Use to split up files that aren't separable by line

(trackerB第7个视频和第1个重复了)

trackerC的第1个视频是圆桌问答之类的  

####TRAINING: Data Science with Apache Spark (Advanced)

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第2个视频39:49（5hours）  

####Automated Machine Learning Using Spark Mllib to Improve Customer Experience

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第3个视频04:15  

####Solving Low Latency Query Over Big Data with Spark SQL

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第3个视频30:12  

####A Big Data Lake Based on Spark for BBVA Bank

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第3个视频01:02:40  

####Sqoop on Spark for Data Ingestion

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第3个视频01:22:05  

(第4个视频打不开)

####Use of Spark MLlib for Predicting the Offlining of Digital Media

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视频09:09  

####Spark and Spark Streaming at Netflix

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视频37:48  

####Lessons Learned with Spark at the US Patent & Trademark Office

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视频01:13:02  

####Appraiser : How Airbnb Generates Complex Models in Spark for Demand Prediction

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视频2:08:22  

####Integrating Spark and Solr

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视频2:42:00  

####Diagnosing Open-Source Community Health with Spark

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视频3:15:30  

####Building a Data Warehouse for Business Analytics using Spark SQL

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视频3:40:12  

####Towards Benchmarking Modern Distributed Streaming Systems

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视频4:10:36  

####Migrating Complex Data Aggregation from Hadoop to Spark

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视频4:40:32  

####The Little Warehouse That Couldn’t, Or: How We Learned to Stop Worrying and Move to Spark

[video](http://livestream.com/accounts/8038169/sparksummit2015-trackc) - 第5个视频4:59:26  


