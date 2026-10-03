    class Solution {
    public:
        void nse(vector<int>&nse , vector<int>&arr ){
            stack<int>st;
            int n=arr.size();
            for(int i=n-1 ; i>=0 ; i--){
                while(!st.empty() && arr[st.top()] > arr[i])st.pop();
                nse[i]= st.empty() ? n : st.top();
                st.push(i);
            }
        }
        void pse(vector<int>&pse , vector<int>&arr ){
            stack<int>st;
            int n=arr.size();
            for(int i=0 ; i<n ; i++){
                while(!st.empty() && arr[st.top()] >= arr[i])st.pop();
                pse[i]= st.empty() ? -1 : st.top();
                st.push(i);
            }
        }
        int sumSubarrayMins(vector<int>& arr) {
            int n=arr.size();
            vector<int>ns(n);
            vector<int>ps(n);
            pse(ps,arr);
            nse(ns,arr);
            long long mo=1e9+7;
            long long t=0;
            for(int i= 0 ; i<arr.size() ; i++){
                long long left=i-ps[i];
                long long right=ns[i]-i;
                t=(t+(left*right*arr[i])%mo)%mo;
            }
            return int(t);
        }
    };