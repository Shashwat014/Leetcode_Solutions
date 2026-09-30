class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mpp;
        int l=0 , r=0 , len=0 , n=fruits.size(),k=2;
        bool f=true;
        while(r<n){
           if(f){ mpp[fruits[r]]++;}
            if(mpp.size() > k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0)mpp.erase(fruits[l]);
                l++;
                f=false;
                continue;
            }
            len=max(len,r-l+1);
            f=true;
            r++;
        }
        return len;
    }
};