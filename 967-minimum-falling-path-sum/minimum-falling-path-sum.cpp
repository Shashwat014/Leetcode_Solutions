class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
    // tabulation
    // thinks in opposite way  u thinks in memo....ie bottom to up

    // int m=matrix.size();
    // int n=matrix[0].size();
    // vector<vector<int>>dp(m,vector<int>(n,-1));
    // for(int i=0 ; i<n ; i++){
    //     dp[m-1][i]=matrix[m-1][i];
    // }
    // for(int r=m-2 ; r>=0 ; r--){
    //     for(int c=0 ; c<n ; c++){
    //         int left=c>0?dp[r+1][c-1] :INT_MAX;
    //         int down=dp[r+1][c];
    //         int right=c<n-1?dp[r+1][c+1]:INT_MAX;
    //         dp[r][c]=matrix[r][c]+min(left , min(down,right));
    //     }
    // }
    // int ans=INT_MAX;
    // for(int i=0;i<n;i++){
    //     ans=min(ans,dp[0][i]);
    // }
    // return ans;
    // }
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int>next(n,-1);
    for(int i=0 ; i<n ; i++){
        next[i]=matrix[m-1][i];
    }
    for(int r=m-2 ; r>=0 ; r--){
        vector<int>cur(n,-1);
        for(int c=0 ; c<n ; c++){
            int left=c>0?next[c-1] :INT_MAX;
            int down=next[c];
            int right=c<n-1?next[c+1]:INT_MAX;

            cur[c]=matrix[r][c]+min(left , min(down,right));
        }
        next=cur;
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,next[i]);
    }
    return ans;
    }
};


// memoization

/*class Solution {
public:
    int fun(int r , int c  , vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int m=matrix.size();
        int n=matrix[0].size();
        if(r==m-1)return dp[r][c]=matrix[r][c];
        if(dp[r][c]!=-1)return dp[r][c];
        int delr[]={1,1,1};
        int delc[]={-1,0,1};
        int sum=INT_MAX;
        for(int i=0 ; i<3 ;i++){
            int nr=r+delr[i];
            int nc=c+delc[i];
            if(nr>=0 && nr<m && nc>=0 && nc <n){
            sum=min(sum , fun(nr,nc,matrix , dp));
            }
        }
        return dp[r][c]= matrix[r][c]+sum;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=INT_MAX;
        for(int i=0; i<n ; i++){
            ans=min(ans , fun(0 , i , matrix , dp));
        }
        return ans;
    }
};*/