class Solution {
public:
    void solve(vector<int>& candidates, int target, int idx,
               vector<int>& combi, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(combi);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            if (candidates[i] > target)
                break;

            combi.push_back(candidates[i]);

            // i, not i+1
            // because same number can be used again
            solve(candidates, target - candidates[i],
                  i, combi, ans);

            combi.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> combi;

        solve(candidates, target, 0, combi, ans);

        return ans;
    }
};