class Solution {
public:
    vector<string> ans;

    void solve(int open, int close, int n, string& current) {

        // Complete valid parentheses string
        if (current.size() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add opening bracket
        if (open < n) {
            current.push_back('(');
            solve(open + 1, close, n, current);
            current.pop_back();
        }

        // Add closing bracket
        if (close < open) {
            current.push_back(')');
            solve(open, close + 1, n, current);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string current;
        solve(0, 0, n, current);
        return ans;
    }
};

