class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // vector<vector<char>>grid(m , vector<char>(n, '.'));
        vector<string>ans;
        for(int i=0 ; i<m ; i++){
            string a="";
            for(int j=0 ; j<n ; j++){
                if(i==0)a.append(".");
                else if(j==n-1)a.append(".");
                else a.append("#");
            }
            ans.push_back(a);
        }

        return ans;
    }
};