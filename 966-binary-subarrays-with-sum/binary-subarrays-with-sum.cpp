class Solution {
public:
    int fun(vector<int>& nums, int goal){
        if(goal<0)return 0;
        int l=0 ,r=0 ,c=0,s=0;
        while(r<nums.size()){
            s+=nums[r];
            while(s>goal)s-=nums[l++];
            c+=(r-l+1);
            r++;
        }
        return c;
    } 
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int n=nums.size();
        // int cnt=0;
        // for(int i=0;  i<n ; i++){
        //     int s=0;
        //     for(int j=i ; j<n ; j++){
        //         s+=nums[j];
        //         if(s>goal)break;
        //         else if(s==goal)cnt++;
        //     }
        // }
        // return cnt;

        return fun(nums,goal)-fun(nums,goal-1);

    }
};