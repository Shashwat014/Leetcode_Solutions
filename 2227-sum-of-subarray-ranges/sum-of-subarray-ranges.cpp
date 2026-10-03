class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long t=0;
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
        long long mi=INT_MAX ,ma=INT_MIN;
            for(int j=i ; j<n ; j++){
                mi= min(mi,1LL*nums[j]);
                ma= max(ma,1LL*nums[j]);
            t+=ma-mi;
            }
        }
        return t;
    }
};