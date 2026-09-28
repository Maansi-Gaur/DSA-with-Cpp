class Solution {
public:
    bool isMatch(string str, string pattern) {
        int n = pattern.length();
        int m = str.length();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {

                // both string and pattern finished
                if (i == n && j == m) {
                    dp[i][j] = true;
                }

                // pattern finished but string remains
                else if (i == n) {
                    dp[i][j] = false;
                }

                // string finished
                else if (j == m) {
                    if (pattern[i] == '*')
                        dp[i][j] = dp[i + 1][j];
                    else
                        dp[i][j] = false;
                }

                else {
                    // ?
                    if (pattern[i] == '?') {
                        dp[i][j] = dp[i + 1][j + 1];
                    }

                    // *
                    else if (pattern[i] == '*') {
                        dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
                    }

                    // same character
                    else if (pattern[i] == str[j]) {
                        dp[i][j] = dp[i + 1][j + 1];
                    }

                    else {
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[0][0];
    }
};