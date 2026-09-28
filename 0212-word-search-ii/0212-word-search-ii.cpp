class Solution {
public:

    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            for(int i = 0; i < 26; i++)
                child[i] = NULL;

            word = "";
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> ans;
    int m, n;

    void insert(string s) {
        TrieNode* curr = root;

        for(char ch : s) {
            int idx = ch - 'a';

            if(curr->child[idx] == NULL)
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->word = s;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {

        if(i < 0 || i >= m || j < 0 || j >= n)
            return;

        char ch = board[i][j];

        if(ch == '#')
            return;

        TrieNode* next = node->child[ch - 'a'];

        if(next == NULL)
            return;

        if(next->word != "") {
            ans.push_back(next->word);
            next->word = "";   // duplicate avoid
        }

        board[i][j] = '#';

        dfs(board, i + 1, j, next);
        dfs(board, i - 1, j, next);
        dfs(board, i, j + 1, next);
        dfs(board, i, j - 1, next);

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        m = board.size();
        n = board[0].size();

        // Build Trie
        for(string word : words)
            insert(word);

        // Start DFS from every cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};