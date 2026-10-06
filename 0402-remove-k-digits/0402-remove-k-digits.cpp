class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char c : num) {
            while(!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // If k still left, remove from end
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build result
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int i = 0;
        while(i < res.size() && res[i] == '0') i++;
        res = res.substr(i);

        return res == "" ? "0" : res;
    }
};
