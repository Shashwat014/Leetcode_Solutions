class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())return 0;
        int l=0,r=1;
        int si=s.size();
        map<char,int>mpp;
        int len=1;
        mpp[s[0]]=0;
        while(r<=si-1){
            if(mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l){
                l=mpp[s[r]]+1;
            }
            
            mpp[s[r]]=r;
            len=max(len , r-l+1);
            r++;
        }
    return len;
    }
};