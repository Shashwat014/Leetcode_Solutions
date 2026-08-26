class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int j=1;
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]%k == 0){
                if(nums[i]/k == j)j++;
                else if(nums[i]/k == j-1)continue;
                else return k*j;
            }
        }
        return k*j;

    }
};