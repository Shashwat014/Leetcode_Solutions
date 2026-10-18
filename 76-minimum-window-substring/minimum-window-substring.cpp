class Solution {
public:
    string minWindow(string s, string t) {
        int m=t.size();
        int n=s.size() , l=0 , r=0 , c=0 , si=-1 , len=INT_MAX;
        map<char , int > mpp;
        for(int i=0 ; i<m ; i++)mpp[t[i]]++;

        while(r<n){
            mpp[s[r]]--;
            if(mpp[s[r]] >= 0)c++;
            while(c==m){
                mpp[s[l]]++;
                if(mpp[s[l]] > 0)c--;
               if(r-l+1 < len){
                len=r-l+1;
                si=l;
               }
                l++;
            }
            r++;
        }
        return si==-1? "" : s.substr(si,len);
    }
};