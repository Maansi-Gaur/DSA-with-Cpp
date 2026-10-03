class Solution {
public:
    int solve(string &s, int left, int right, int k) {
        if (right - left < k)
            return 0;

        int freq[26] = {0};

        for (int i = left; i < right; i++)
            freq[s[i] - 'a']++;

        for (int i = left; i < right; i++) {
            if (freq[s[i] - 'a'] < k) {

                int a = solve(s, left, i, k);
                int b = solve(s, i + 1, right, k);

                return max(a, b);
            }
        }

        return right - left;
    }

    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size(), k);
    }
};