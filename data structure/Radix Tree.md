###Radix Tree(基数树)

> Wikipedia  
> In computer science, a **radix tree** (also **patricia trie**, **radix trie**, or **compact prefix tree**) is a data structure that represents a space-optimized trie in which each node that is the only child is merged with its parent.
> 
> ![example of a radix tree](https://upload.wikimedia.org/wikipedia/commons/a/ae/Patricia_trie.svg)

Linux radix tree最广泛的用途是内存管理，结构address_space通过radix tree跟踪绑定到地址映射上的核心页，该radix tree允许内存管理代码快速查找标识为dirty或writeback的页。Linux radix tree的API在lib/radix-tree.c中实现。  



**参考文献**  

[Radix Tree - Wikipedia](https://en.wikipedia.org/wiki/Radix_tree)  
[joker0910-基数树(radix tree)](http://blog.csdn.net/joker0910/article/details/8250085)