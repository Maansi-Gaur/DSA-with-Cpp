class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        unordered_map<long long, int> mp;
        vector<int> best(n + 1, INT_MAX);

        mp[0] = 0;

        long long prefix = 0;
        int ans = INT_MAX;

        for (int i = 1; i <= n; i++) {
            prefix += arr[i - 1];

            long long need = prefix - target;

            if (mp.find(need) != mp.end()) {
                int start = mp[need];
                int len = i - start;

                if (best[start] != INT_MAX) {
                    ans = min(ans, best[start] + len);
                }

                best[i] = min(best[i - 1], len);
            }
            else {
                best[i] = best[i - 1];
            }

            mp[prefix] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};