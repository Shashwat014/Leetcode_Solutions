class Solution {
public: 
    void fun(vector<vector<int>>& grid, vector<vector<int>>& vis,int r , int c, int k , long long &s){
        vis[r][c]=1;
        s+=grid[r][c];
        int n=grid.size();
        int m=grid[0].size();
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        for(int i=0 ; i<4 ; i++){
            int nr=r+delr[i];
            int nc=c+delc[i];
            if(nr>=0 && nr<n && nc>=0 &&nc<m && grid[nr][nc]!=0 && vis[nr][nc]==0){
                fun(grid , vis ,nr,nc,k,s);
            }
        }

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]!=0 && vis[i][j]==0){
                    long long s=0;
                    fun(grid , vis , i , j , k,s);
                    if ( s % k == 0)ans++;
                }
            }
        }
        return ans;
        }
};