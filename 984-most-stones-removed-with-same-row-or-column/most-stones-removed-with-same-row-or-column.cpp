class disjointset{
    public:
    vector<int>parent , size;
    disjointset(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0 ; i<n ;i++){
            parent[i]=i;
        }
    }

    int findupar(int n){
        if (parent[n]==n)return n;
        return parent[n]=findupar(parent[n]);
    }
    void unionbysize(int u , int v){
        int pu = findupar(u);
        int pv = findupar(v);
        if(pu==pv)return;
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int mr=0 , mc=0;
        for(auto it: stones){
            mr=max(mr , it[0]);
            mc=max(mc , it[1]);
        }
        disjointset ds = disjointset(mr+mc+2);
        // treating whole row and column as complete node
        unordered_map<int,int>stonenodes;
        for(auto it:stones){
            int r=it[0];
            int c=it[1];
            int colnode=mr+c+1;
            ds.unionbysize(r,colnode);
            stonenodes[r]=1;
            stonenodes[colnode]=1;
        }
        int comp=0;
        for(auto it:stonenodes){
            if(ds.findupar(it.first)==it.first)comp++;
        }
        return n-comp;
    }
};