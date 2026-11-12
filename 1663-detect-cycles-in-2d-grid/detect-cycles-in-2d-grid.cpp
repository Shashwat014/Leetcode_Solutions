class Solution {
public:
    bool fun(vector<vector<int>>&vis , vector<vector<char>>& grid , int r, int c,int pr,int pc){
        vis[r][c]=1;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        char a=grid[r][c];
        for(int i=0 ; i<4 ; i++){
            int nr=r+delr[i];
            int nc=c+delc[i];
            if(nr>=0 && nr<n && nc>=0 &&nc<m && grid[nr][nc]==a){ 
                if(!vis[nr][nc]){
                    bool s=fun(vis,grid,nr,nc,r,c);
                    if(s)return true;
                }
                else if(nr!=pr&&nc!=pc)return true;
            }
        }  
        return false;     
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(vis[i][j]==0){
                  if( fun(vis,grid,i,j,-1,-1))return true;
                  
                }
            }
        }
        return false;
    }
};