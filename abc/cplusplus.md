#C++

##类型转换

###强制类型转换

- **dynamic_cast**：将一个基类对象指针（或引用）cast到继承类型的指针，支持运行时识别指针或引用所指向的对象。如果绑定到引用或指针的对象不是目标类型的对象，则dynamic_cast失败。如果转换到指针类型的dynamic_cast失败，则dynamic_cast的结果为0；如果转换到引用类型的dynamic_cast失败，则抛出一个bad_cast类型异常。【就是说这货会进行类型检查哟】
- **const_cast**：转换掉表达式的const性质（删除const），但其实依然只能读不能写
- **static_cast**：编译器隐式执行的任何类型转换都可以由static_cast显示完成
- **reinterpret_cast**：为操作数的位模式提供较低层次的重新解释

##extern "C"

##typedef和#define
define只是在编译预处理时进行简单替换，不做正确性检查，不管含义是否相关
typedef是为了增加可读性起的别名，是在编译时期的处理

```
typedef (int*) pINT;
#define pINT2 int*

pINT a,b; //相当于int*a;int*b;
pINT2 a,b; //相当于int*a,b;

```

##程序空间

1. text段：程序代码，编译时确定，只读
2. bss段：定义而没有赋初值的全局变量和静态变量
3. data段：在编译阶段就能确定的数据，可读可写，赋了初值的全局变量、静态变量和常量
4. 堆：程序员分配释放的区域
5. 栈：函数参数、局部变量

