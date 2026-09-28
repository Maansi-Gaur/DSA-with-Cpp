class Solution {
public:
    bool isMatch(string s, string p) {

        vector<vector<bool>> dp(p.length() + 1,
                                vector<bool>(s.length() + 1, false));

        for (int i = 0; i < dp.size(); i++) {

            for (int j = 0; j < dp[0].size(); j++) {

                // Empty pattern + empty string
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }

                // Empty pattern
                else if (i == 0) {
                    dp[i][j] = false;
                }

                // Empty string
                else if (j == 0) {

                    char pc = p[i - 1];

                    if (pc == '*') {
                        dp[i][j] = dp[i - 2][j];
                    }
                    else {
                        dp[i][j] = false;
                    }
                }

                else {

                    char pc = p[i - 1];
                    char sc = s[j - 1];

                    // Current pattern character is *
                    if (pc == '*') {

                        // Ignore x*
                        dp[i][j] = dp[i - 2][j];

                        char pslc = p[i - 2];

                        // x* can match current character
                        if (pslc == '.' || pslc == sc) {
                            dp[i][j] = dp[i][j] || dp[i][j - 1];
                        }
                    }

                    // Current pattern character is .
                    else if (pc == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }

                    // Characters match
                    else if (pc == sc) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }

                    // Characters don't match
                    else {
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[p.length()][s.length()];
    }
};