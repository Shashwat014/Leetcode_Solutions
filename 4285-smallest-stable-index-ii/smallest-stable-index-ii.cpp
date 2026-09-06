class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n= nums.size();
        int maxi[n], mini[n];
        int ma=INT_MIN;
        int mi=INT_MAX;
        for(int i=0 , j=n-1 ; i<n ; i++,j--){
            ma=max(ma,nums[i]);
            mi=min(mi,nums[j]);
            maxi[i]=ma;
            mini[j]=mi;
        }
        for(int i=0 ; i<n ;i++){
            if(maxi[i]-mini[i] <= k)return i;
        }
        return-1;
    }
};