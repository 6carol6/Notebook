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

            //
        }
    }
}