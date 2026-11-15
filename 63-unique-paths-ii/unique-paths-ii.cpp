class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // memoization recursion and tabulation leet 62

        // space optimization

        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0])return 0;
        if(m==1&&n==1&&!obstacleGrid[0][0])return 1;
        vector<int>prev(n,0);
        for(int r=0 ; r<m ; r++){
            vector<int>cur(n,0);
            for(int c=0 ;c<n ; c++){
                if(r==0 && c==0)cur[c]=1;
                else{
                    if(obstacleGrid[r][c]==1)cur[c]=0;
                    else{
                        int up=prev[c];
                        int left=c>0?cur[c-1]:0;
                        cur[c]=up+left;
                    }
                }
            }
            prev=cur;
        }
        return prev[n-1];
    }
};