class Solution {
public:

    set<string> combine(set<string>& a, set<string>& b) {
        set<string> ans;

        for (string x : a) {
            for (string y : b) {
                ans.insert(x + y);
            }
        }

        return ans;
    }

    set<string> solve(string& s, int& i) {

        set<string> ans;
        set<string> curr;
        curr.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++;  // skip {

                set<string> temp = solve(s, i);

                i++;  // skip }

                curr = combine(curr, temp);
            }

            else if (s[i] == ',') {

                for (string x : curr)
                    ans.insert(x);

                curr.clear();
                curr.insert("");

                i++;
            }

            else {

                string ch(1, s[i]);

                set<string> temp;
                temp.insert(ch);

                curr = combine(curr, temp);

                i++;
            }
        }

        // Add the last part
        for (string x : curr)
            ans.insert(x);

        return ans;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};