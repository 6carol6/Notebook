# C++

## 类型转换

### 强制类型转换

- **dynamic_cast**：将一个基类对象指针（或引用）cast到继承类型的指针，支持运行时识别指针或引用所指向的对象。如果绑定到引用或指针的对象不是目标类型的对象，则dynamic_cast失败。如果转换到指针类型的dynamic_cast失败，则dynamic_cast的结果为0；如果转换到引用类型的dynamic_cast失败，则抛出一个bad_cast类型异常。【就是说这货会进行类型检查哟】
- **const_cast**：转换掉表达式的const性质（删除const），但其实依然只能读不能写
- **static_cast**：编译器隐式执行的任何类型转换都可以由static_cast显示完成
- **reinterpret_cast**：为操作数的位模式提供较低层次的重新解释

## extern "C"

## typedef和#define
define只是在**编译预处理**时进行简单替换，不做正确性检查，不管含义是否相关
typedef是为了增加可读性起的别名，是在**编译**时期的处理

```
typedef (int*) pINT;
#define pINT2 int*

pINT a,b; //相当于int*a;int*b;
pINT2 a,b; //相当于int*a,b;

```

## new/operator new/placement new

- new: 是一个操作符，不能被重载。总是：1) 调用operator new分配内存 2) 调用构造函数生成对象 3) 返回相应指针
- operator new: 可以被重载，同理operator new[], operator delete, operator delete[]也可以被重载
- placement new: 是operator new的一个重载版本，不分配内存，而是指向已经分配好的某段内存的一个指针，因此不能删除它，但需要调用对象的析构函数
    - 缓存提前分配
        - 堆
        ```
           class Task;
           char* buf = new [N*sizeof(Task)];
        ```
        - 栈
        ```
           class Task;
           char buf[N*sizeof(Task)];
        ```
        - 直接使用地址（地址必须有意义）：```void* buf = reinterpret_cast<void*>(0xF00F);```
    - 对象分配：```Task* ptask = new (buf) Task;```
    - 使用：正常用就行
    - 对象的析构：``` ptask->~Task();```
    - 释放：```delete[] buf```

## 程序空间

1. text段：程序代码，编译时确定，只读
2. bss段：定义而没有赋初值的全局变量和静态变量
3. data段：在编译阶段就能确定的数据，可读可写，赋了初值的全局变量、静态变量和常量
4. 堆：程序员分配释放的区域
5. 栈：函数参数、局部变量

## RAII(Resource acquisition is initialization)

实际上就是一个栈上对象，利用栈上临时对象生命周期程序自动管理的特点  
提供了一种资源自动管理的方式，当产生异常、回滚等现象时，RAII可以正确释放掉资源

```
    class RAII{
    public:
        RAII(Resource* aResource):r_(aResource){}
        ~RAII() {delete r_;}
        Resource* get() { return r_;}
    private:
        Resource* r_;
    };

```

## RTTI (Run-Time Type Identification，执行期类型识别)

通过运行时类型信息程序能够使用基类的指针或引用来检查这些指针或引用所指对象的实际派生类型  

1. typeid
2. dynamic_cast

## 动态链接库

### 查看可执行文件链接了哪些动态库

ldd

## C++11

###左值和右值的区别

### 右值引用和转发型引用

### 移动构造函数

### 智能指针

- shared_ptr：允许多个指针指向同一个对象
    ```
        shared_ptr<int> p(new int(1024));//不可以写shared_ptr<int> p = new int(1024)，因为构造函数是explicit的
    ```
- unique_ptr：独占所指向的对象
- weak_ptr：弱引用，指向shared_ptr所管理的对象
