class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long fh=0 , sh=0 ;
        int ans=0;
        for(int i=0 ; i<n ; i++){
            if(i<n/2){
                fh+=nums[i];
            }
            else sh+=nums[i];
        }
        // if(fh>sh) ans++;
        int i=0 , j=n/2;
        for(int k=0;k<n ;k++){
            fh+=(-nums[i%n]+nums[j%n])*1LL;
            sh+=(-nums[j%n]+nums[i%n])*1LL;
            if(fh>sh)ans++;
            i++;
            j++;
        }
        return ans;
    }
};