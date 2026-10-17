class Solution {
public:
    int fun(vector<int>& nums, int k){
        int l=0 , r=0 , c=0,s=0;
        map<int,int>mpp;
        while(r<nums.size()){
            nums[r]%=2;
            mpp[nums[r]]++;
            s+=nums[r];
            while(s>k){
                s-=nums[l];
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)mpp.erase(nums[l]);
                l++;
            }
            c+=r++ -l +1;
        }
        return c;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};