class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int l=0 , h=nums.size()-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m]==t)return true;
            if(nums[l]==nums[m] && nums[m]==nums[h]){
                h--;
                l++;
                continue;
            }
            if(nums[m] <= nums[h]){
                if(nums[m] < t && t<=nums[h])l=m+1;
                else h=m-1;
            }
            else {
                if(nums[l] <=t && t<nums[m])h=m-1;
                else l=m+1;
            }
        }
        return false;
    }
};