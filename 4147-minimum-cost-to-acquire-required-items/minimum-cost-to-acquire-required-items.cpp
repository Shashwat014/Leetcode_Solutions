class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1==0 && need2==0)return 0;
        long long cost=0;
        long long p=min(need1,need2);
        cost+=min(costBoth,cost1+cost2)*p;
        cost+=min(costBoth , cost1) * (need1-p);
        cost+=min(costBoth , cost2) * (need2-p);
        return cost;
    }
};