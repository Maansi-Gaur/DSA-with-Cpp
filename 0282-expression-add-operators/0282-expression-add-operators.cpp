class Solution {
public:

    void solve(string &num, long long target, int idx,
               string expr, long long result, long long prev,
               vector<string>& ans) {

        // All digits used
        if (idx == num.size()) {
            if (result == target) {
                ans.push_back(expr);
            }
            return;
        }

        for (int i = idx; i < num.size(); i++) {

            // Leading zero not allowed
            if (i > idx && num[idx] == '0')
                break;

            string currStr = num.substr(idx, i - idx + 1);

            long long curr = stoll(currStr);

            // First number
            if (idx == 0) {
                solve(num, target, i + 1,
                      currStr, curr, curr, ans);
            }

            else {

                // +
                solve(num, target, i + 1,
                      expr + "+" + currStr,
                      result + curr,
                      curr,
                      ans);

                // -
                solve(num, target, i + 1,
                      expr + "-" + currStr,
                      result - curr,
                      -curr,
                      ans);

                // *
                solve(num, target, i + 1,
                      expr + "*" + currStr,
                      result - prev + prev * curr,
                      prev * curr,
                      ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;

        solve(num, target, 0, "", 0, 0, ans);

        return ans;
    }
};