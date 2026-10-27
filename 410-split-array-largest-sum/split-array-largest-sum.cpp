class Solution {
public: 
    int fun(vector<int>& nums , int maxsum){
        int n=nums.size();
        int subsum=0;
        int sp=1;
        for(int i=0 ; i<n ; i++){
            if(subsum+nums[i] > maxsum){
                sp++;
                subsum=nums[i];
            }
            else subsum+=nums[i];
        }
        return sp;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=INT_MIN,h=0 , n=nums.size();
        for(int i=0 ;i<n ;i++){
            l=max(l , nums[i]);
        h+=nums[i];
        }
        while(l<=h){
            int m=l+(h-l)/2;
            int split = fun(nums , m);
            if(split> k)l=m+1;
            else h=m-1;
            
        }
        return l;
    }
};