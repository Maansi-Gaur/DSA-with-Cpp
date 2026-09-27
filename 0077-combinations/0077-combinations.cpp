class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int start, int n, int k, vector<int>& temp) {
        
        // k elements choose ho gaye
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++) {
            
            // Choose
            temp.push_back(i);

            // Explore
            solve(i + 1, n, k, temp);

            // Undo
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1, n, k, temp);
        return ans;
    }
};