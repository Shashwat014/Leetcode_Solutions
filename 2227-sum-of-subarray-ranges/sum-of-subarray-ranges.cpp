class Solution {
public:
    void ns(vector<int>& arr , vector<int>&nse){
        stack<int>st;
        for(int i=arr.size()-1 ; i>=0 ; i--){
            while(!st.empty() && arr[st.top()] > arr[i])st.pop();
            nse[i]=st.empty() ? arr.size() : st.top();
            st.push(i);
        }
    }
    void ng(vector<int>& arr , vector<int>&nge){
        stack<int>st;
        for(int i=arr.size()-1 ; i>=0 ; i--){
            while(!st.empty() && arr[st.top()] < arr[i])st.pop();
            nge[i]=st.empty() ? arr.size() : st.top();
            st.push(i);
        }
    }
    void ps(vector<int>& arr , vector<int>&pse){
        stack<int>st;
        for(int i=0 ; i<arr.size() ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i])st.pop();
            pse[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    void pg(vector<int>& arr , vector<int>&pge){
        stack<int>st;
        for(int i=0 ; i<arr.size() ; i++){
            while(!st.empty() && arr[st.top()] <= arr[i])st.pop();
            pge[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    long long mini(vector<int>&nums){
        int n=nums.size();
        vector<int>pse(n);
        vector<int>nse(n);
        ps(nums,pse);
        ns(nums,nse);
        long long  t=0;
        for(int i=0 ; i<n ; i++){
            long long left = 1LL*(i-pse[i]);
            long long  right=1LL*(nse[i]-i);
            t+=right*left*nums[i];
        }
        return t;
    }
    long long maxi(vector<int>&nums){
        int n=nums.size();
        vector<int>pge(n);
        vector<int>nge(n);
        pg(nums,pge);
        ng(nums,nge);
        long long t=0;
        for(int i=0 ; i<n ; i++){
            long long left = (i-pge[i])*1LL;
            long long right=(nge[i]-i)*1LL;
            t+=right*left*nums[i]*1LL;
        }return t;

    }
    long long subArrayRanges(vector<int>& nums) {
        // long long t=0;
        // int n=nums.size();
        // for(int i=0 ; i<n ; i++){
        // long long mi=INT_MAX ,ma=INT_MIN;
        //     for(int j=i ; j<n ; j++){
        //         mi= min(mi,1LL*nums[j]);
        //         ma= max(ma,1LL*nums[j]);
        //     t+=ma-mi;
        //     }
        // }
        // return t

        // it gives o(n2)


        // sum of subarray max - sum of subarray min
        return 1LL*(maxi(nums)-mini(nums));
    }
};