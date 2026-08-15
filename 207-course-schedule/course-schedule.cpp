class Solution {
private:
    bool dfs(int i , vector<vector<int>>& adj , vector<int>&vis , vector<int>&pathvis ){
        vis[i]=1;
        pathvis[i]=1;
        for(auto it : adj[i]){
            if(!vis[it]){
                if(!dfs(it , adj , vis , pathvis))return false;
            }
            else if(pathvis[it])return false;
        }
        pathvis[i]=0;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // using topological sort

        // vector<vector<int>> adj(numCourses);
        // for(auto it : prerequisites){
        //     adj[it[1]].push_back(it[0]);
        // }
        // vector<int>indegree(numCourses,0);
        // for(int i =0 ; i<numCourses ; i++){
        //     for(auto it : adj[i]){
        //         ++indegree[it];
        //     }
        // }
        // queue<int>q;
        // int cnt=0;
        // for(int i=0 ; i<numCourses ; i++){
        //     if(indegree[i]==0)q.push(i);
        // }
        // while(!q.empty()){
        //     auto it=q.front();
        //     q.pop();
        //     cnt++;
        //     for(auto i : adj[it]){
        //         --indegree[i];
        //         if(indegree[i]==0)q.push(i);
        //     }
        // }
        // if(cnt==numCourses)return true;
        // return false;

        // using cycle detection in derected graph

        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        vector<vector<int>> adj(numCourses);
            for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            }
            for(int i=0 ; i<numCourses ; i++){
                if(!dfs( i , adj ,vis ,pathvis ))return false;
            }
    return true;
    }
};