class disjointset{
public:
    vector<int>parent,size;
    disjointset(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0 ; i<n ; i++){
            parent[i]=i;
        }
    }
    int findupar(int u){
        if(parent[u]==u)return u;
        return parent[u]=findupar(parent[u]);
    }
    void unionbysize(int u ,int v){
        int pu=findupar(u);
        int pv=findupar(v);
        if(pu==pv)return ;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string , int>mp;
        disjointset ds=disjointset(10000);        
        for(int i=0 ; i<accounts.size() ; i++){
            for(int j=1 ; j<accounts[i].size() ; j++){
                auto s=accounts[i][j];
                if(mp.find(s)==mp.end()){
                    mp[s]=i;
                }
                else ds.unionbysize( i , mp[s]);
            }
        }
        // putting mail into another list by pointing to ultimate parent
        vector<string>a[accounts.size()];
        for(auto it:mp){
            auto m=it.first;
            a[ds.findupar(it.second)].push_back(m);
        }

        // now putting it into ans
        vector<vector<string>>ans;
        for(int i=0 ; i<accounts.size() ; i++){
            if(a[i].size()==0)continue;
            sort(a[i].begin() , a[i].end());
            vector<string>t;
            t.push_back(accounts[i][0]);//store first name and then store it all mail then push into ans
            for(auto it : a[i]){
                t.push_back(it);
            }
            ans.push_back(t);

        }
        return ans;
    }
};