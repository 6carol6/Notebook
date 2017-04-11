### 收发消息

1. 收消息的类必须继承ProtobufProcess<T>{};
2. 消息必须在messages/messages.proto里注册（照着别的消息写就行啦）
3. 在1中的类里注册消息处理函数

### 参考文献

[1] [http://dongxicheng.org/apache-mesos/mesos-libprocess/](http://dongxicheng.org/apache-mesos/mesos-libprocess/)
