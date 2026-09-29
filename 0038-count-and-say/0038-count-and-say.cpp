class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int i = 1; i < n; i++) {
            string next = "";

            for (int j = 0; j < ans.size(); j++) {
                int count = 1;

                while (j + 1 < ans.size() && ans[j] == ans[j + 1]) {
                    count++;
                    j++;
                }

                next += to_string(count);
                next += ans[j];
            }

            ans = next;
        }

        return ans;
    }
};
//hmesha purane wale ko dekh