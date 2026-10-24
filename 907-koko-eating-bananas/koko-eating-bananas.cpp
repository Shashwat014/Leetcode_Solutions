class Solution {
public:
    long long fun(vector<int>& piles, int h){
        long long t=0;
        for(int i=0 ; i<piles.size() ; i++){
            // t+=long long(ceil((double)piles[i]/(double)h));
            t+=ceil((piles[i] +1LL*h -1)/h);

        }
        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi=INT_MIN , l=1;
        for(int i =0 ; i<piles.size() ; i++){
            hi=max(hi,piles[i]);
        }
        int k=INT_MAX;
        while(l<=hi){
            int m=l+(hi-l)/2;
            long long rt=fun(piles , m);
            if(rt<=h){
                k=min(k,m);
                hi=m-1;
                }
            else l=m+1;
        }
        return k;
    }
};