#Language Level, java.util

##ArrayList, Vector

1. Vector是线程安全的，ArrayList不是，ArrayList性能更好
2. 当元素超过初始大小时，Vector把容量翻倍，而ArrayList增加50%

##String, StringBuffer, StringBuilder

1. String: 字符串常量，不可变。
2. StringBuffer: 字符串变量，线程安全，可频繁更改(append(), insert())，也可toString()
3. StringBuilder: 字符串变量，非线程安全，用在字符串缓冲区被单个线程使用的时候。

##HashMap, HashTable, HashSet, LinkedHashMap(LinkedHashMapEntry), ConcurrentHashMap

1. HashTable是线程安全的，HashMap不是
2. Hashtable缺省初始大小为a，载入因子为b(0<b<1)，则当元素个数超过ab时，就会重新组织内存并增加大小
3. aa


#Concurrent, java.util.concurrent