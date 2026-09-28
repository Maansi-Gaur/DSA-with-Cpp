class Solution {
public:
    int minCut(string s) {

        int n = s.length();

        // dp[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int gap = 0; gap < n; gap++) {

            for(int i = 0, j = gap; j < n; i++, j++) {

                if(gap == 0) {
                    dp[i][j] = true;
                }
                else if(gap == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
            }
        }

        // strg[i] = minimum cuts needed for s[0...i]
        vector<int> strg(n);

        strg[0] = 0;

        for(int j = 1; j < n; j++) {

            if(dp[0][j]) {
                strg[j] = 0;
            }
            else {

                int mn = INT_MAX;

                for(int i = j; i >= 1; i--) {

                    if(dp[i][j]) {
                        mn = min(mn, strg[i - 1]);
                    }
                }

                strg[j] = mn + 1;
            }
        }

        return strg[n - 1];
    }
};