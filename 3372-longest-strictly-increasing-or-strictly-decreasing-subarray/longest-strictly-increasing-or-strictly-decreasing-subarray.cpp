class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int si=1,sd=1,ti=1,td=1;
        int n=nums.size();
        int i=0,j=1;
        while(i<n&&j<n){
            if(nums[i]<nums[j])ti++;
            else {si=max(si,ti);
                ti=1;
            }
            if(nums[i]>nums[j])td++;
            else {
                sd=max(sd,td);
                td=1;
            }
            i++;
            j++;
        }
        si=max(si,ti);
        sd=max(sd,td);
        return max(si,sd);
    }
};