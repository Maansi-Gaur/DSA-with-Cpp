class Solution {
public:
    vector<string> ans;

    string keypad[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int idx, string &curr) {

        // We have processed all digits
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        // Get letters corresponding to current digit
        string letters = keypad[digits[idx] - '0'];

        for (char ch : letters) {

            curr.push_back(ch);              // choose

            backtrack(digits, idx + 1, curr); // explore

            curr.pop_back();                 // undo
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        string curr = "";

        backtrack(digits, 0, curr);

        return ans;
    }
};