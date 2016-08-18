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
5. HashMap/HashTalbe都是链表散列结构
6. HashTable/HashMap缺省初始大小为a，载入因子为b(0<b<1)，则当元素个数超过ab时，就会重新组织内存并增加大小

###ConcurrentHashMap(jdk1.5), HashMap, HashTable

1. ConcurrentHashMap是线程安全的HashMap
2. ConcurrentHashMap使用分段锁保证线程安全（区别HashTable）。ConcurrentHashMap把数据按hash(key)划分成不同的分段(Segement)，每一个分段就相当于一个HashTable，以保证同步。
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

#Concurrent, java.util.concurrent(jdk1.5)

