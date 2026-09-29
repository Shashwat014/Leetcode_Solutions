class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int>st;
        int l=0,r=0,len=0,n=nums.size();
        while(r<n){
            if(nums[r]==0){
                st.push(r);
                if(k-1<0){
                    l=st.front()+1;
                    k++;
                    st.pop();
                }
                k--;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};