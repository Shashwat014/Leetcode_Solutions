class Solution {
public:


    void fun(vector<vector<int>>& grid , vector<vector<int>>& vis , int r , int c){
        vis[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        int delr[]={0 ,1 ,0, -1};
        int delc[]={1,0,-1,0};
        for(int i=0 ; i<4 ; i++){
            int nr=r+delr[i];
            int nc=c+delc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 0 && vis[nr][nc]==0)fun(grid , vis ,nr,nc);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0 ; j<m ; j++){
            if(vis[0][j] == 0 && grid[0][j]==0)fun(grid , vis , 0 , j);
        }
        for(int j=0 ; j<m ; j++){
            if(vis[n-1][j] == 0 && grid[n-1][j]==0)fun(grid , vis , n-1 , j);
        }
        for(int i=0 ; i<n ; i++){
            if(vis[i][0] == 0 && grid[i][0]==0)fun(grid , vis , i , 0);
        }
        for(int i=0 ; i<n ; i++){
            if(vis[i][m-1] == 0 && grid[i][m-1]==0)fun(grid , vis , i , m-1);
        }
        int ans=0;
        for(int i=1 ; i<n-1 ; i++){
            for(int j=1 ; j<m-1 ; j++){
                if(grid[i][j] == 0 && vis[i][j] == 0){
                    ans++;
                    fun(grid,vis,i,j);
                }
            }
        }
    return ans;
    }
};