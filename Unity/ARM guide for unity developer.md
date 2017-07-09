# Chapter 4 - Optimization Lists

## 4.1 Application processor optimization

### 1 用coroutines取代Invoke()

`Monobehaviour.Invoke()`能够控制一个函数在一定delay时间后被调用，然而有一些局限：

- 该函数需要借助C#的反射机制来找到被调用的函数，会比直接调用慢。
- 对函数签名不做编译时检查
- 不支持额外的参数

可以使用coroutine来取代。coroutine是一个`IEnumerator`类型的函数，

### 