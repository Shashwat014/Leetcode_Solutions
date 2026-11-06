class Solution {
public:
    // simple recursion

    // int fun(int n , int& k){
    //     if(n==0) return ++k;
    //     if(n>0)
    //     int left = fun(n-1, k);
    //     if(n>1) {
    //         int right=fun(n-2,k);
    //     }
    //      return k;
    // }

    // int climbStairs(int n) {
    //     int ans=0;
    //     return fun(n,ans);
    // }

    // memoization 

    int fun(int n , vector<int>&dp){
        if(n==0 )return 1;
        if(n==1 )return 1;
        if(dp[n]!=-1)return dp[n];
        int left = fun(n-1,dp);
        int right=fun(n-2,dp);
        return dp[n]=left+right;
    }

    int climbStairs(int n) {
        int ans=0;
        vector<int>dp(n+1,-1);
        return fun(n,dp);
    }
};