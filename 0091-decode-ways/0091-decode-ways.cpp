class Solution {
public:
    int numDecodings(string str) {
        int n = str.length();

        if(str[0] == '0')
            return 0;

        vector<int> dp(n, 0);
        dp[0] = 1;

        for(int i = 1; i < n; i++) {

            // 00, 01, 02... invalid
            if(str[i - 1] == '0' && str[i] == '0') {
                dp[i] = 0;
            }

            // previous is 0, current is non-zero
            else if(str[i - 1] == '0' && str[i] != '0') {
                dp[i] = dp[i - 1];
            }

            // current is 0
            else if(str[i] == '0') {
                if(str[i - 1] == '1' || str[i - 1] == '2')
                    dp[i] = (i >= 2 ? dp[i - 2] : 1);
                else
                    dp[i] = 0;
            }

            // both non-zero
            else {
                int num = stoi(str.substr(i - 1, 2));

                dp[i] = dp[i - 1];

                if(num <= 26)
                    dp[i] += (i >= 2 ? dp[i - 2] : 1);
            }
        }

        return dp[n - 1];
    }
};