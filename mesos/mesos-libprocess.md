### 收发消息

1. 收消息的类必须继承ProtobufProcess<T>{};
2. 消息必须在messages/messages.proto里注册（照着别的消息写就行啦）
3. 在1中的类里注册消息处理函数

### google ProtoBuffers

1. 上一节的.proto是google ProtoBuf的结构化数据定义
2. 这种数据结构类似XML，不过更小、更快、更简单
3. 可以自动生成get, set函数之类的东西
4. 类的属性类型可以有`required`, `repeated`, `optional`
	- `required`表示必选字段
	- `repeated`是list
	- `optional`表示可选字段

### 参考文献

[1] [http://dongxicheng.org/apache-mesos/mesos-libprocess/](http://dongxicheng.org/apache-mesos/mesos-libprocess/)  
[2] [google ProtoBuffers](https://developers.google.com/protocol-buffers/)  
