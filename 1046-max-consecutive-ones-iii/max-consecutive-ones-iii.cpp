class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,len=0,n=nums.size();
        while(r<n){
            if(nums[r]==0){
                if(k-1<0){
                    while(nums[l]!=0){
                        l++;
                    }
                    l++;
                    k++;
                }
                k--;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};