class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0 , r=1, k=1 , n=nums.size();
        while(r<n){
            if(nums[l]==nums[r])r++;
            else{
                nums[++l]=nums[r++];
                k++;
            }
        }
        return k;
    }
};