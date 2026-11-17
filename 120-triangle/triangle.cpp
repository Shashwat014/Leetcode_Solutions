class Solution {
public:
    int fun(int i, int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        int n=triangle.size();
        // no of element in each row =i+1
        if(i==n-1)return dp[i][j]= triangle[i][j];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int down=fun(i+1 , j ,triangle,dp);
        int right= j+1<i+2 ? fun(i+1 , j+1 , triangle,dp) : INT_MAX;
        return dp[i][j]= triangle[i][j]+min(down,right);

    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n=triangle.size();
        vector<vector<int>>dp( n ,vector<int>(n+1,INT_MAX));
        if(n==1)return triangle[0][0];
        return fun(0,0,triangle,dp);
    }
};