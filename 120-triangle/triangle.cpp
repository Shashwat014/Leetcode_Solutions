class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //tabulation and space optimization
        int n=triangle.size();
        vector<int>next(n,INT_MAX);
        for(int i=0 ; i<n;i++){
            next[i]=triangle[n-1][i];
        }
        for(int i=n-2 ; i>=0 ;i--){
            vector<int>cur(n , INT_MAX);
            for(int j=0 ; j<i+1 ; j++){
                int down=next[j];
                int right=next[j+1];
                cur[j]=triangle[i][j]+min(down,right);
            }
            next=cur;
        }
        return next[0];
    }
};



// memoization
/*class Solution {
public:
    int fun(int i, int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        int n=triangle.size();
        // no of element in each row =i+1
        if(i==n-1)return dp[i][j]= triangle[i][j];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int down=fun(i+1 , j ,triangle,dp);
        int right= fun(i+1 , j+1 , triangle,dp) ;
        return dp[i][j]= triangle[i][j]+min(down,right);

    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n=triangle.size();
        vector<vector<int>>dp( n ,vector<int>(n+1,INT_MAX));
        if(n==1)return triangle[0][0];
        return fun(0,0,triangle,dp);
    }
};*/