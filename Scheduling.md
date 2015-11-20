###Scheduling

��ͷ��ƪ���¶�����UC Berkeley��[Mosharaf Chowdhury](https://amplab.cs.berkeley.edu/author/mchowdhury)�����Կ�����Χ��Coflow�ĵ��ȵġ���һƪ��������ΪCoflow��ģ������ƪ����inter-coflow scheduling����һƪ���·�����Hotnets'12������ƪ�ֱ𷢱���SIGCOMM'14��'15��  

####Coflow: A Networking Abstraction for Cluster Application

��ƪ���¶���Coflow��
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

��Ⱥ��size�͸��Ӷȱ��Խ��Խ���ˣ�providing scalable and predictable performance is an increasingly important challenge. ���predictable performance��һ���ؼ����ϰ�����stragglers��������Щ��Ԥ�뻨�Ѹ���ʱ����ɵ����񣩡����stragglers�����е���õĽ����������*speculation*��Ҳ�������ѡ����copyִ�У�Ȼ��ѡ�����������Ǹ������In this work, we present **Hopper**, a job scheduler that is speculation-aware, i.e., that integrates the tradeoffs associated with speculation into job scheduling decisions.  

��Ȼ����Ϊstraggler����speculative copies�Ǻ��ձ�Ľ��straggler������������ƪ��������ѡ��straggler��speculative copies��������job��origin copies��  