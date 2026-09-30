class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);

        int row = 0;
        int step = 1;

        for (char ch : s) {
            rows[row] += ch;

            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;

            row += step;
        }

        string ans;

        for (int i = 0; i < rows.size(); i++) {
           ans += rows[i];
        }

        return ans;
    }
};