class Solution {
public:
    int fun(vector<int>& nums, int k){
        map<int,int>mpp;
        int l=0 ,r=0 ,c=0;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)mpp.erase(nums[l]);
                l++;
                }
            c+=r-l+1;
            r++;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return fun(nums , k)-fun(nums , k-1);  
    }
};