class Solution {
public:
    int minDays(vector<int>& bloomday, int m, int k) {
        // if(m*k > bloomday.size())return -1;
        // int mi=INT_MAX,ma=INT_MIN;
        // for(int i=0 ; i<bloomday.size() ; i++){
        //     mi=min(mi,bloomday[i]);
        //     ma=max(ma,bloomday[i]);
        // }
        // for(int i=mi ; i<=ma ; i++){
        // int b=0,cnt=0;
        // for(int j=0 ; j<bloomday.size() ; j++){
        //     if(bloomday[j] <= i)cnt++;
        //     else {
        //         b+=cnt/k;
        //         cnt=0;
        //     }
        // }
        // b+=cnt/k;
        // if(b>=m)return i;
        // }
        // return -1;

        // Binary search on answers

        if (1LL*m * k > bloomday.size())
            return -1;
        int mi = INT_MAX, ma = INT_MIN;
        for (int i = 0; i < bloomday.size(); i++) {
            mi = min(mi, bloomday[i]);
            ma = max(ma, bloomday[i]);
        }
        int l = mi, h = ma , ans=0;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int b = 0, cnt = 0;
            for (int j = 0; j < bloomday.size(); j++) {
                if (bloomday[j] <= mid)
                    cnt++;
                else {
                    b += cnt / k;
                    cnt = 0;
                }
            }
            b += cnt / k;
            if(b >= m ){
                h=mid-1;
                ans=mid;
            }
            else l=mid+1;
            
        }
        return ans;
    }
};