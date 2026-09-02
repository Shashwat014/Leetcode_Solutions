class Solution {
private:
   void dfs(int n,int p , vector<int>&vis , vector<int>adj[] , vector<vector<int>> &bridges,int tin[] , int low[], int &t){
        vis[n]=1;
        tin[n]=low[n]=t++;
        for(auto it: adj[n]){
            if(it==p)continue;
            if(!vis[it]){
                dfs(it , n ,vis,adj,bridges,tin,low,t);
                low[n]=min(low[n] , low[it]);
                if(low[it]>tin[n])bridges.push_back({it,n});
            }
            else{ // we are not checking for bridge here cuz if the adj node is already visited that means we are travelling in the same path on the adj node is visited then there is no point to break the edge if it breaks we still have other way to reach adj
                low[n]=min(low[n] , low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
         vector<int>adj[n];
         
            for(auto it :connections){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
        
         vector<int>vis(n,0);
         vector<vector<int>> bridges;
         int timer=0;
         int tin[n],low[n];
         dfs(0 ,-1, vis , adj , bridges,tin,low, timer);
         
         return bridges;
    }
};