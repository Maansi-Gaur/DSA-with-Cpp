class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for(int k = 2; k <= n; k++) {

            string ans = "";
            int count = 1;

            for(int i = 1; i < s.size(); i++) {

                if(s[i] == s[i-1]) {
                    count++;
                }
                else {
                    ans += to_string(count);
                    ans += s[i-1];
                    count = 1;
                }
            }

            // last group
            ans += to_string(count);
            ans += s[s.size()-1];

            s = ans;
        }

        return s;
    }
};
//hmesha purane wale ko dekh