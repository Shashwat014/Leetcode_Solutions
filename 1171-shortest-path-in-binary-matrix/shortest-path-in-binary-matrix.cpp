class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)return -1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int i=-1 ; i<=1 ;i++){
                for(int j=-1 ; j<=1 ; j++){
                    int nr=r+i;
                    int nc=c+j;
                    if(nr>=0&&nr<n&&nc>=0&&nc<m && grid[nr][nc]==0 &&dist[nr][nc]>d+1){
                        dist[nr][nc]=d+1;
                        q.push({d+1,{nr,nc}});
                    }
                    if(nr==n-1&&nc==m-1&& grid[nr][nc]==0)return dist[nr][nc];
                }
            }
        }
        return -1;
    }
};