class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {

            vector<long long> ndp(k, 0);

            // Start a new subarray
            ndp[num % k]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newR = (r * (num % k)) % k;
                ndp[newR] += dp[r];
            }

            dp = ndp;

            // Add subarrays ending at current index
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};