class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[nums.size()-1] !=nums[nums.size()-2])return nums[nums.size()-1];
        int l=1 , h=nums.size()-2;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]!=nums[m-1]&&nums[m]!=nums[m+1])return nums[m];
            else if(m%2==1){
                if(nums[m]==nums[m-1])l=m+1;
                else h=m-1;
            }
            else{
                if(nums[m]==nums[m-1])h=m-1;
                else l=m+1;
            }
        }
        return -1;
    }
};