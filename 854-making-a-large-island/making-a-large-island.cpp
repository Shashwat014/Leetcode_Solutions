class disjointset{
    public:
        vector<int>parent,size;
        disjointset(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0 ; i<n  ;i++){
                parent[i]=i;
            }
        }
        int findupar(int n){
            if(n==parent[n])return n;
            return parent[n]=findupar(parent[n]); // path  compression
        }
        void unionbysize(int u ,int v){
            int pu=findupar(u);
            int pv=findupar(v);
            if(pu==pv)return;
            if(size[pu] < size[pv]){
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
            else{
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        disjointset ds = disjointset(n*m);

        // step 1 kepp the existing 1 together in the originol components
        int delcol[]={0,1,0,-1};
        int delrow[]={-1,0,1,0};
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==0)continue;
                    for(int k=0 ; k<4 ; k++){
                        int nr=i+delrow[k];
                        int nc=j+delcol[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<m){
                            int n=i*m+j;
                            int a=nr*m+nc;
                            if(grid[nr][nc]==1)ds.unionbysize(n,a);
                        }
                    }
            }
        }

        // step 2 check the most suitable place for changing 0  to 1
        int mx=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]==1)continue;
                set<int>comp;
                for(int i=0;i<4;i++){
                    int nr=r+delrow[i];
                    int nc=c+delcol[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        if(grid[nr][nc]==1){
                            comp.insert(ds.findupar(nr*m+nc));
                        }
                    }
                }
            int s=1;//for 0 converted to 1
            for(auto it:comp){
                s+=ds.size[it];
            }
            mx=max(mx,s);
            }
        }
        // what if all cell contains 1
        for(int cellno=0;cellno<n*m;cellno++){
            mx=max(mx,ds.size[ds.findupar(cellno)]);

        }
      return mx;  
    }
};