class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int s=0,c=0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]==1){
                c++;
            }
            else c=0;
            s=max(s,c);
        }
        return s;
    }
};