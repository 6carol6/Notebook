#Language Level, java.util

##ArrayList, Vector

1. Vector是线程安全的，ArrayList不是，ArrayList性能更好
2. 当元素超过初始大小时，Vector把容量翻倍，而ArrayList增加50%

##String, StringBuffer, StringBuilder

1. String: 字符串常量，不可变。
2. StringBuffer: 字符串变量，线程安全，可频繁更改(append(), insert())，也可toString()
3. StringBuilder: 字符串变量，非线程安全，用在字符串缓冲区被单个线程使用的时候。

##HashXX

###HashMap(jdk1.2), HashTable

1. HashTable在每个方法上使用synchronized保证线程安全，HashMap不是线程安全的
2. HashMap可以使用null作为key或value,HashTable不可;
3. `HashTable extends Dictionary implements Map, Cloneable`  
   `HashMap extends AbstractMap implements Map, Cloneable, Serializable`
4. HashTable直接使用key的hashCode作为key，HashMap会对key的hashCode进行二次hash，不过这方面性能差异不大
5. HashMap/HashTalbe都是链表散列结构，但在java8中，如果HashMap的entry链长度超过8，就会转换成红黑树
6. HashTable/HashMap缺省初始大小为a，载入因子为b(0<b<1)，则当元素个数超过ab时，就会重新组织内存并增加大小

###ConcurrentHashMap(jdk1.5), HashMap, HashTable

1. ConcurrentHashMap是线程安全的HashMap
2. ConcurrentHashMap使用分段锁保证线程安全（区别HashTable）。ConcurrentHashMap把数据按hash(key)划分成不同的分段(Segement)，每一个Segement继承自ReentrantLock，以保证同步。
3. 若需要跨段操作，比如size(), containsValue()，则需要按顺序锁定所有Segment

###LinkedHashMap(LinkedHashMapEntry)

1. LinkedHashMap是HashMap的一个子类，能够保留元素插入的顺序
2. LinkedHashMap在HashMap部分跟HashMap的实现是一样的，但是在每一个entry，除了保存当前对象的引用，还有before和after，因此插入的所有元素还组成了一个双向链表

###HashSet

1. HashSet是用HashMap来存储所有元素的（只用key）
2. HashSet是一个Set，并没有value

##XXSet

###HashSet, TreeSet

1. HashSet是HashMap实现的，TreeSet是TreeMap实现的，而TreeMap是红黑树

###抽象类和接口

1. 可以实现多个接口，抽象类只能被单继承
2. 接口中定义的方法不能实现，抽象类可以实现部分方法
3. 接口中的数据成员默认是`public static final`的，方法默认是`public abstract`的，interface只能被`public`,`abstract`修饰

#Concurrent, java.util.concurrent(jdk1.5)

##Executors(线程池)

    ```
    ExecutorService executor = Executors.newFixedThreadPool(3);//设置最大3个线程
    executor.execute(new PrintChar('a',100));
    ...
    executor.shutdown();
    ```

##volatile

1. 每次读到的都是新值
2. 禁止被编译器优化

##lock, ReentrantLock(重入锁), synchronized

1. 使用synchronized，若`A`不释放，`B`会一直等下去不会被中断  
   使用ReentrantLock，若`A`不释放，可以使`B`在等待足够长时间之后会中断等待，干别的事情（使用`tryLock()`而不是`lock()`）
2. synchronized是JVM层面上实现的，可以被监控工具监控，在代码执行出现异常时，JVM会自动释放锁  
   lock是通过代码实现的，要保证一定会被释放就一定要放到finally{}中
3. 在资源竞争不是很激烈的情况下，synchronized性能优于ReetrantLock，反之synchronized性能会下降，但ReetrantLock保持性能

#JVM

##Java内存分配

- 线程共享
    1. 方法区
    2. 堆区
- 线程隔离
    3. 程序计数器（PC）
    4. 虚拟机栈
    5. 本地方法栈
    
###堆区分配

在虚拟机遇到`new`指令后，会把相应类加载到方法区，然后为新生对象在堆区分配内存。
1. 对象头（长度必须是8N，否则补齐）：
    - Mark Word: HashCode，GC分代年龄，锁状态标志，线程持有锁，偏向线程ID，偏向时间戳
    - 类型指针
    - 若是Java数组还要记录长度
2. 实例数据
3. 对齐填充（由于对象的起始地址必须是8的整数倍）

分配方式（取决于GC方式）：
- 指针碰撞（Serial, ParNew, 带Compact的收集器）
- 空闲列表（CMS，基于标记清楚的收集器）

对象分配的同步处理（保证不会申请到同一块空间）：
- CAS（Compare and Swap，CPU支持的对内存中共享数据进行操作的特殊指令）+ 失败重试
- 本地线程分配缓冲TLAB（可设置）

对象分配完成之后会把除对象头之外分配空间置为0，然后设置对象头
