class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long s=0;
        for(int i=0 ; i<n ; i++){
            nums[i]*=nums[i];
            s+=nums[i]*1LL;
        }
        sort(nums.begin() , nums.end());
        for(int i=0 ; i<n/2 ; i++){
            s-=2LL*nums[i];
        }
        return s;
    }
};