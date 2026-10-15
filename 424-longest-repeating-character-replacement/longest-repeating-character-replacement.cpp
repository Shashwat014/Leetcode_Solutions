class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,len=0,f=0 , n=s.size();
        map<int , int>mpp;
        while(r<n){
            mpp[s[r]-'A']++;
            f=max(f,mpp[s[r]-'A']);
            int changes = (r-l+1)-f;
            if(changes > k){
                mpp[s[l++] - 'A']--;
            }
            if((r-l+1)-f <= k ){
                len=max(len , r-l+1);
            }
            r++;
        }
        return len;
    }
};