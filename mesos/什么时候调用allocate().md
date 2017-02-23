###hierarchical.cpp中的allocate()什么时候会被调用？

在hierarchical的以下函数被调用时，会被调用。

1. addFramework
2. activateFramework
3. reviveOffers
4. setQuota
5. removeQuota
6. updateWeights
7. resume

这些函数是master接收到相应消息之后在master.cpp的函数中被调用的

###消息是谁发出来的？

应该是framework的RPC吧。

