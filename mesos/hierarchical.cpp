void HierarchicalAllocatorProcess::allocate(
    const hashset<SlaveID>& slaveIds_)
{
    ++metrics.allocation_runs; //用来统计的

    // 对于每个framework计算可用资源
    // (1) 对于slave上保留的资源，根据role给framework分配
    // (2) 对于slave上没有保留的资源，分配给任意role
    hashmap<FrameworkID, hashmap<SlaveID, Resources>> offerable;

    // NOTE: 这个函数只能操作一个slave的子集，
    // 我们必须保证我们当统计那个子集的资源的时候，we don't assume cluster knowledge

    vector<SlaveID> slaveIds;
    slaveIds.reserve(slaveIds_.size());

    // 过滤掉不是白名单中的或者是已经deactivated的slave
    foreach (const SlaveID& slaveId, slaveIds_){
        if(isWhitelisted(slaveId) && slaves[slaveId].activated){
            slaveIds.push_back(slaveId);
        }
    }

    // 随机排列slave
    std::random_shuffle(slaveIds.begin(), slaveIds.end());

    // 返回留给quota role的资源总量
    // 因为我们考虑了保留资源和quota的持续持有资源，因此先
    auto getQuotaRoleAllocatedResources = [this](const string& role){
        CHECK(quotas.contains(role));


        Resources resources;

        foreach (Resource resource,
                quotaRoleSorter->allocationScalarQuantities(role)){
            CHECK(!resource.has_reservation());
            CHECK(!resource.has_disk());

            resource.set_role("*");
            resources += resource;
        }
        return resources;
    };

    // 由于allocation有两个stage，
    hashmap<SlaveID, Resources> offeredSharedResources;

    foreach (const SlaveID& slaveId, slaveIds){
        foreach (const string& role, quotaRoleSorter->sort()){
            CHECK(quotas.contains(role));

            // 如果在这个role里没有active的framework，我们就不需要放置这个role了
            if(!activeRoles.contains(role)) continue;

            // 得到分配给quota role的总资源量
            Resources roleConsumedResources = 
            getQuotaRoleAllocatedResources(role);

            // 如果quota for the role is satisfied,我们就不需要再为这个role分配资源了（至少在这个stage不用了）
            if (roleConsumedResources.contains(quotas[role].info.guarantee())) {
                continue;
            }

            // 根据fair share取出frameworks
            foreach (const string& frameworkId_, frameworkSorters[role]->sort()) {
                FrameworkID frameworkId;
                frameworkId.set_value(frameworkId_);

                // 只有对GPU有要求而且slave有GPU的才会取得GPU
                if (!frameworks[frameworkId].gpuAware &&
                   slaves[slaveId].total.gpus().getOrElse(0) > 0) {
                    continue;
                }

                // 计算每个slave上现有的资源
                Resources available = (slaves[slaveId].total - slaves[slaveId].allocated).nonShared();

                // 如果a shared 资源还没有在这个offer cycle提供给一个framework，就offer它
                if (frameworks[frameworkId].shared){
                    available += slaves[slaveId].total.shared();
                    if (offeredSharedResources.contains(slaveId))
                        available -= offeredSharedResources[slaveId];
                }

                // 可以被分配的资源 = 为role保留的 + 不保留资源
                Resources resources = 
                    (available.unreserved() + available.reserved(role)).nonRevocable();
                
                // 所有同一个Role下的framework都会考虑相同的资源，
                // 在这种情况下，我们就没有可放置的资源了
                // 对于同一个role下的其他framework就不用再考虑了，直接break掉
                if (!allocatable(resources)) break;
                
                if (isFiltered(frameworkId, slaveId, resources))
                    continue;
                
                VLOG(2) << "Allocating " << resources << " on agent " << slaveId
                << " to framework " << frameworkId
                << " as part of its role quota";

                offerable[frameworkId][slaveId] += resources;
                offeredSharedResources[slaveId] += resources.shared();

                slaves[slaveId].allocated += resources;

                // 根据role和framework的fair share来分配
                // NOTE:不能用的资源以及被排除了
                frameworkSorters[role]->add(slaveId, resources);
                frameworkSorters[role]->allocated(frameworkId_, slaveId, resources);
                roleSorter->allocated(role, slaveId, sources);
                quotaRoleSorter->allocated(role, slaveId, resouces);
            }
        }
    }

    // 计算下一个round可用的scalar resources（包括可撤回和保留的资源）
    // 这样就不会在下一个stage over-allocate资源了
    Resources remainingClusterResources = 
    roleSorter->totalScalarQuantities();
    foreachkey (const string& role, activeRoles){
        reaminingClusterResources -=
        roleSorter->allocationScalarQuantities(role);
    }

    // quota'ed role会先暂时用过滤offer来拒绝资源
    // 因此quotas可能不能完全被放置
    // 所以就有剩下的资源啦
    Resources unallocatedQuotaResources;
    foreachpair (const string& name, const Quota& quota, quotas){
        Resources allocated = getQuotaRoleAllocatedResources(name);
        const Resources required = quota.info.guarantee();
        unallocatedQuotaResources += (required - allocated);
    }

    // 看看下一个stage还有多少可以分配的呀
    remainingClusterResources -= unallocatedQuotaResources;

    // 
    remainingClusterResources = remainingClusterResources.nonShared();

    // 为了保证我们不在第二个阶段over-allocate resources
    // 我们用了2 stopping criteria:
    //    *


    Resources allocatedStage2;

    
}