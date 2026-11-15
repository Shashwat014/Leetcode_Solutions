// memoization
/* int fun(int r,int c , vector<vector<int>> &dp){
        if(r==0 && c==0)return dp[r][c]= 1;
        if(r<0 || c<0)return 0;
        if(dp[r][c] != -1)return dp[r][c];
        int up = fun( r-1 , c , dp);
        int left = fun(r, c-1 , dp);
        return dp[r][c]=up+left;   
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m-1,n-1 ,dp);
    }*/

// tabulation
/*vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(i==0 && j==0)dp[i][j]=1;
                else {
                    int up = i>0 ? dp[i-1][j]  :0    ;
                    int left = j>0 ? dp[i][j-1]  : 0   ;
                    dp[i][j]=up+left;

                }
            }
        }
        return dp[m-1][n-1];*/

class Solution {
public:
    // space optimization
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        for(int r=0 ; r<m ; r++){
            vector<int>cur(n,0);
            for(int c=0 ; c<n ;c++){
                if(r==0 && c==0)cur[c]=1;
                else {
                    int up=prev[c];
                    int left=c>0?cur[c-1]:0;
                    cur[c]=up+left;

                }
            }
            prev=cur;
        }
        return prev[n-1];
    }
};