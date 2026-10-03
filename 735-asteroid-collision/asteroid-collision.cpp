class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        // vector<int> s;
        // for (int i = 0; i < a.size(); i++) {
        //     if (a[i] > 0)
        //         s.push_back(a[i]);
        //     else {
        //         while (!s.empty() && s.back() > 0 && s.back() < abs(a[i])) {
        //             s.pop_back();
                
        //     }
        //     if (!s.empty() && s.back() == abs(a[i])) {
        //         s.pop_back();
        //     } 
        //     else if (s.empty() || s.back() < 0) {
        //         s.push_back(a[i]);
        //     }
        // }}
        // return s;

        stack<int>st;
        int r=0 , n=a.size();
        while(r<n){
            if(st.empty()){
                st.push(a[r++]);
                continue;
            }
            // if(a[r] > 0 && st.top()  <0 ){
            //     if(abs(st.top())  > a[r]){
            //         r++;

            //     }
            //     else if(abs(st.top()) == a[r]){
            //         st.pop();
            //         r++;
            //     }
            //     else{st.pop();}
            // }
            if(a[r] < 0 && st.top() > 0){
                if( abs(a[r]) > st.top() ){
                    st.pop();
                }
                else if(abs(a[r])==st.top()){
                    st.pop();
                    r++;
                }
                else{r++;}
            }
            else{
                st.push(a[r++]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};