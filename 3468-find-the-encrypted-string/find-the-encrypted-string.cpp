class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n=s.size();
        string ans;
        // for(int i=0 ; i<n ; i++){
        //     int l=i;
        //     for(int j=0 ; j<k ;j++ ){
        //         l++;
        //         l=l%n;
        //     }
        //     ans+=s[l];
        // }
        for(int i=0 ; i<n ; i++){
            ans+=s[(i+k)%n];
        }
        return ans;
    }
};