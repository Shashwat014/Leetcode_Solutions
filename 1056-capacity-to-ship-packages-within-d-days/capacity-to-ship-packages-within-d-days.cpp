class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=INT_MIN , h=0;

        for(int i=0 ; i<weights.size() ; i++){
            l=max(l,weights[i]);
            h+=weights[i];
        }

        while(l<=h){
            int m=l+(h-l)/2;
            int w=0 , t=1;
            for(int i=0 ; i<weights.size() ; i++){
                if(w+weights[i] > m){
                    t++;
                    w=weights[i];
                }
                else{
                    w+=weights[i];
                }
            }
            if( t <= days)h=m-1;
            else l=m+1;
        }
        return l;
    }
};