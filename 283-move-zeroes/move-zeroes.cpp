class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z=0,j=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(j>=nums.size() || z>=nums.size())break;
            while(nums[z]!=0){
                z++;
                if(z>=nums.size())break;
                }
                if(z>=nums.size())break;
            if(nums[z]==0 && nums[j]==0){
                j++;
                continue;
            }
            if(z > j){
                j++;
                continue;
            }
            swap(nums[z] , nums[j++]);

        }
    }
};