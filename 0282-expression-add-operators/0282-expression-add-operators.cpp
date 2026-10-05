class Solution {
public:
    vector<string> ans;

    vector<string> addOperators(string s, int target) {
        helper(s, target, 0, "", 0, 0);
        return ans;
    }

    void helper(string s, int target, int i, string path,
                long eval, long residual) {

        // Base case
        if (i == s.length()) {
            if (eval == target) {
                ans.push_back(path);
            }
            return;
        }

        string currStr;
        long num = 0;

        // Backtracking loop
        for (int j = i; j < s.length(); j++) {

            // Leading zero handle coz 01 ya 08 kuch ni hota ya rto 1 hota h ya 8
            if (j > i && s[i] == '0')
                return;

            currStr += s[j];
            num = num * 10 + (s[j] - '0');

            // First number
            if (i == 0) {
                helper(s, target, j + 1,
                       path + currStr,
                       num, num);
            }
            else {

                // +
                helper(s, target, j + 1,
                       path + "+" + currStr,
                       eval + num,
                       num);

                // -
                helper(s, target, j + 1,
                       path + "-" + currStr,
                       eval - num,
                       -num);

                // *
                helper(s, target, j + 1,
                       path + "*" + currStr,
                       eval - residual + residual * num,
                       residual * num);
            }
        }
    }
};