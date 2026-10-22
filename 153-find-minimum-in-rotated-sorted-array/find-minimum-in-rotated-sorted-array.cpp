class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0 ,h=nums.size()-1 , mi=INT_MAX;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m] < nums[h]){
                mi=min(mi , nums[m]);
                h=m-1;
            }
            else{
                mi=min(mi,nums[l]);
                l=m+1;
            }
        }
        return mi;
    }
};