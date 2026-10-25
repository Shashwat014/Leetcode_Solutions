class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mi=INT_MAX,ma=INT_MIN;
        for(int i=0 ; i<nums.size() ; i++){
            mi=min(mi,nums[i]);
            ma=max(ma,nums[i]);
        }
        int l=1,h=ma;
        while(l<=h){
            int m=l+(h-l)/2;
            int s=0;
            for(int i=0 ; i<nums.size() ; i++){
                s+=((nums[i]+m-1)/m);
            }
            if(s<=threshold)h=m-1;
            else l=m+1;
        }
        return l;
    }
};