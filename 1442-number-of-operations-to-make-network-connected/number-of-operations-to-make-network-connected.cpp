class disjointset{
public:
    vector<int>parent,size;
    disjointset(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0 ; i<n ;i++){
            parent[i]=i;
        }
    }
    int findupar(int n){
        if(parent[n]==n)return n;
        return parent[n]=findupar(parent[n]);
    }
    void unionbysize(int u , int v){
        int pu=findupar(u);
        int pv=findupar(v);
        if(pv==pu)return;
        if(size[pu] > size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        disjointset ds=disjointset(n);
        for(auto it : connections){
            // adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int comp=0 , e=0;
        for(int i=0 ; i<n ; i++){
            for(auto it : adj[i]){
                if(ds.findupar(i) == ds.findupar(it)){
                    e++;
                }
                else ds.unionbysize(i,it);
            }
        }
        for(int i=0 ; i<n ;i++){
            if(ds.parent[i]==i)comp++;
        }
        if(e >= comp-1)return comp-1;
        return -1;
    }
};