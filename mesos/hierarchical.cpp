class HierarchicalAllocatorProcess:public MesosAllocatorProcess{

    //有一些addFramework() removeFramework()
    // reviveOffers() 之类的函数


    struct Framework{};
    hashmap<FrameworkID, Framework> frameworks;

    struct Slave{
        // 常规(regular)和过多订购(oversubscribed)的资源总量
        Reources total;

        // 唱过和过多订购的已经被分配的资源
        // 虽然sorter中也记录了这个信息，但是如果一些framework没有重新注册，
        // sorter中的这个信息不准确
        Resources allocated;

        // available = total - allocated
        // slave不可能会被over-allocated，也就是说allocated>total是不可能的

        bool activated; // 是否提供资源

        std::string hostname;

        //表示一个scheduled unavailability因为要为一个指定的slave保留
        struct Maintenance{};
    };
    hashmap<SlaveID, Slave> slaves;

    // 每个role注册的framework的数量
    // 当role的active count掉到0，从map中删除
    hashmap<std::string, size_t> activeRoles;

    // 为每个role设置权重，如果不存在，默认weight=1
    hashmap<std::string, double> weights;

    // 为每个role设置最低票数(quotas)
    // quota优先于fair share
    hashmap<std::string, Quota> quotas;

    // slave可以send offer给whitelist
    Option<hashset<std::string>> whitelist;

    // 不参与role's fair share的资源
    Option<std::set<std::string>> fairnessExcludeResourceNames;

    // allocation一共分为两步，每一步都遵循该步的sorter
    // 第一步，资源只分配给拥有quota set roles的framework
    // 第二步，剩下的资源被分配
    //
    // 每一步(stage)由两个阶段(level)的sorting组成，所以叫“hierarchical”
    // Level1 sorts across roles
    // Level2 sorts across frameworks within a particular role
    //
    // allocator依赖于'Sorter'的规则，每个阶段(level)都有自己的Sorter
    
    // active roles的一个sorter，stage2-level1
    process::Owned<Sorter> roleSorter;

    // 设置了quota的roles专属的sorter，stage1-level1
    process::Owned<Sorter> quotaRoleSorter;

    // stage1/2-level2
    // 一个Sorter的集合，每一个元素都是一个role的Sorter
    // 每个Sorter决定同一个role的framework如何排序，如何共享资源
    hashmap<std::string, process::Owned<Sorter>> frameworkSorters;

    // 用于产生frameSorter的工厂
    const std::function<Sorter*()> frameworkSorterFactory;
};

// 有个template继承上面那个类啦
// 为了给工厂传递函数用
template <
    typename RoleSorter,
    typename FrameworkSorter,
    typename QuotaRoleSorter>
class HierarchicalAllocatorProcess
  : public internal::HierarchicalAllocatorProcess
{
public:
  HierarchicalAllocatorProcess()
    : ProcessBase(process::ID::generate("hierarchical-allocator")),
      internal::HierarchicalAllocatorProcess(
          [this]() -> Sorter* {
            return new RoleSorter(this->self(), "allocator/mesos/roles/");
          },
          []() -> Sorter* { return new FrameworkSorter(); },
          []() -> Sorter* { return new QuotaRoleSorter(); }) {}
};