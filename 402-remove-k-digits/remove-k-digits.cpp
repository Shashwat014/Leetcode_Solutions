class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size())
            return "0";
        stack<char> st;
        int n = k;
        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && n > 0 && st.top() > num[i]) {
                st.pop();
                n--;
            }
            st.push(num[i]);
        }
        while (n > 0) {
            st.pop();
            n--;
        }
        string r = "";
        while (!st.empty()) {
            r += st.top();
            st.pop();
        }
        while (r.size() != 0 && r.back() == '0') {
            r.pop_back();
        }
        reverse(r.begin(), r.end());
        if (r.empty())
            return "0";
        return r;
    }
};