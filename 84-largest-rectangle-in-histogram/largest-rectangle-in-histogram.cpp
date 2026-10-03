class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>st;
        int n = h.size();
        int a=0;
        for(int i=0 ; i<n ;i++){
            while(!st.empty() && h[st.top()] > h[i]){
                int e=h[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                a=max(a, e*(nse-pse-1));
            }
            st.push(i);
        }

        // stil left with some element in the stack
        while(!st.empty()){
            int e=h[st.top()];
            st.pop();
            int nse=n;
            int pse=st.empty() ? -1 : st.top();
            a=max(a , e*(nse-pse-1));
        }
        return a;
    }
};