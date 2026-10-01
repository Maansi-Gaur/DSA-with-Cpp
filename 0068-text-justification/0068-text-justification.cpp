class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;

        while (i < words.size()) {
            int j = i;
            int letters = 0;

            // Find how many words can fit in this line
            while (j < words.size() &&
                   letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int spaces = maxWidth - letters;
            int gaps = j - i - 1;

            string line = "";

            // Last line OR only one word
            if (j == words.size() || gaps == 0) {
                for (int k = i; k < j; k++) {
                    if (k > i) line += " ";
                    line += words[k];
                }

                // Left justify
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                // Fully justify
                int evenSpace = spaces / gaps;
                int extraSpace = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += string(evenSpace, ' ');

                        if (extraSpace > 0) {
                            line += " ";
                            extraSpace--;
                        }
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};