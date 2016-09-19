#数据库

##事务

###事务的特性
ACID
1. 原子性 Atomicity
2. 一致性 Consistency
3. 隔离性 Isolation
4. 持久性 Durability

###事务的隔离级别

1. 读未提交 Read uncommitted
2. 读提交 Read committed [大多数数据库默认]：解决脏读
3. 重复读 Repeatable read [MySQL默认]：解决脏读、不可重复读
4. 序列化 Serializable：解决脏读、不可重复读、幻读


##MySQL

###MySQL的锁类型，何时会触发锁

1. 页级: DBD
2. 表级: MyISAM, MEMORY, ISAM
3. 行级: INNODB[MySQL的默认存储引擎]

###MySQL的索引的实现方式