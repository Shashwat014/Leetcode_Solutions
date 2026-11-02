class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0 , h=nums.size()-1;
        if(nums[0]>target)return 0;
        if(nums[nums.size()-1] < target)return nums.size();
        int ind=0;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==target){
                return m;

            }
            else if(nums[m] > target){
                ind=m;
                h=m-1;

            }
            else l=m+1;
        }
        return l;
        }
};