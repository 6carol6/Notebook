## mesos接口

### sorter.hpp

sorter是一个资源分配的排序接口，需要实现的函数如下：  

1. `virtual void initialize(const Option<std::set<std::string>>& fairnessExcludeResourceNames) = 0;`  
    初始化一个sorter
2. `virtual void add(const std::string& client, double weight = 1) = 0;`  
    添加一个client（一个framework或是user）
3. `virtual void update(const std::string& client, double weight) = 0;`  
    添加一个client的权重信息
4. `virtual void remove(const std::string& client) = 0;`  
    删除一个client
5. `virtual void activate(const std::string& client) = 0;`  
    在一个client `deactivate`之后重新加入一个client，如果这个client已经在sort中，无操作
6. `virtual void deactivate(const std::string& client) = 0;`  
    从sort中删除一个client（不进入资源分配），如果这个client本来就不在sort中，无操作
7. `virtual void allocated(const std::string& client, const SlaveID& slaveId, const Resources& resources) = 0;`  
    指出资源已经被一个给定的client使用了
8. `virtual void update(const std::string& client, const SlaveID& slaveId, const Resources& oldAllocation, const Resources& newAllocation) = 0;`  
    对某个client修改部分资源的权重，不能影响static的规则或是资源的总量
9. `virtual void unallocated(const std::string& client, const SlaveID& slaveId, const Resources& resources) = 0;`  
    指出资源已经被一个给定的client释放了
10. `virtual const hashmap<SlaveID, Resources>& allocation(const std::string& client) = 0;`  
    返回已经分配给指定client的资源集合
11. `virtual const Resources& allocationScalarQuantities(const std::string& client) = 0;`  
    返回所有分配给指定client的scalar resource quantities
12. `virtual hashmap<std::string, Resources> allocation(const SlaveID& slaveId) = 0;`  
    返回分配在slave上的所用client
13. `virtual Resources allocation(const std::string& client, const SlaveID& slaveId) = 0;`  
    返回在给定slave上分配给给定client的资源
14. `virtual const Resources& totalScalarQuantities() const = 0;`  
    返回这个sorter中所有的scalar resource quantities
15. `virtual void add(const SlaveID& slaveId, const Resources& resources) = 0;`  
    往资源池中添加资源
16. `virtual void remove(const SlaveID& slaveId, const Resources& resources) = 0;`  
    资源池中删除资源
17. `virtual std::vector<std::string> sort() = 0;`  
    根据sorter的规则，返回client被安排资源的顺序
18. `virtual bool contains(const std::string& client) const = 0;`  
    如果sorter中有specified client，无论是否active都返回true
19. `virtual int count() = 0;`  
    返回sorter管理中的client的数量，无论是否active