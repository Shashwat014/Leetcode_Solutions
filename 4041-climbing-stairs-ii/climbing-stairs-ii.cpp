class Solution {
public:
    int fun(int n , vector<int>&dp ,vector<int>& costs ){
        if(n==0)return dp[n]=0;
        if(dp[n]!=-1)return dp[n];
        int fs=INT_MAX,ss=INT_MAX,ts=INT_MAX;
                fs=fun(n-1 , dp , costs) + costs[n-1]+1;
        if(n>1) ss=fun(n-2 , dp , costs) + costs[n-1]+4;
        if(n>2) ts=fun(n-3 , dp , costs) + costs[n-1]+9;
        return dp[n]=min(fs , min(ss,ts));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return fun(n,dp,costs);
    }
};