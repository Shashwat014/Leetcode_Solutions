class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i=0 ; i<nums.size() ; i++){
            int ma=INT_MIN;
            int mi=INT_MAX;
            for(int f=0 ; f<=i ; f++){
                ma=max(ma,nums[f]);
            }
            for(int s=i ; s<nums.size() ; s++){
                mi=min(mi,nums[s]);
            }
            if(ma-mi <= k)return i;
        }
        return -1;
    }
};