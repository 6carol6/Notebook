###Scheduling

开头三篇文章都来自UC Berkeley的[Mosharaf Chowdhury](https://amplab.cs.berkeley.edu/author/mchowdhury)。可以看到是围绕Coflow的调度的。第一篇文章首先为Coflow建模，后两篇进行inter-coflow scheduling。第一篇文章发表于Hotnets'12，后两篇分别发表于SIGCOMM'14和'15。  

####Coflow: A Networking Abstraction for Cluster Application

这篇文章定义Coflow是
<img src="http://www.forkosh.com/mathtex.cgi? c(S,D)={f_1,f_2,...,f_{|c|}}">
<img src="http://chart.googleapis.com/chart?cht=tx&chl= c(S,D)=\{f_1,f_2,...,f_{|c|}\}" style="border:none;">

####Efficient Coflow Scheduling with Varys



####Efficient Coflow Scheduling Without Prior Knowledge

Existing efficient schedulers require a priori coflow information and ignore cluster dynamics like pipeling, task failures, and speculative executions, which limit their applicability. Schedulers without prior knowledge compromise on performance to avoid head-of-line blocking. In this paper, we present **Aalo** that strikes a balance and efficiently schedules coflows **without prior knowledge**.  

**Problems: coflow schedulers that rely on prior knowledge**  

- Pipelining between successive computation stages: data is transferred as soon as it is generated - making it hard to know the size of each flow.
- Multiple waves in a single stage: preventing all flows within a coflow from starting together.
- Task failures and speculation result in redundant flows: the exact number of flows or their endpoints cannot be determined until a coflow has completed.

####Hopper: Decentralized Speculation-aware Cluster Scheduling at Scale

@California Institute of Technology, Microsoft Research, University of Southern California  

集群的size和复杂度变得越来越大了，providing scalable and predictable performance is an increasingly important challenge. 获得predictable performance的一个关键的障碍就是stragglers（就是那些比预想花费更长时间完成的任务）。面对stragglers，现有的最好的解决方案就是*speculation*，也就是随机选择多个copy执行，然后选择运行最快的那个结果。In this work, we present **Hopper**, a job scheduler that is speculation-aware, i.e., that integrates the tradeoffs associated with speculation into job scheduling decisions.  

当然啦，为straggler创建speculative copies是很普遍的解决straggler慢的做法。这篇文章重在选择straggler的speculative copies还是其他job的origin copies。  