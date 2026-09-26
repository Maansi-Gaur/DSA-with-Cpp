class Solution {
public:
      set <vector<int>> st;
 void solve(vector<int>& candidates, int target, int idx, vector<int>& combi,vector<vector<int>>& ans) {
       

        if(target<0|| idx==candidates.size()) return;

        if(target==0){
            if(st.find(combi)==st.end()){
                ans.push_back(combi);
                st.insert(combi);
                return;
            }
        }
        
        combi.push_back(candidates[idx]);
        solve(candidates,target-candidates[idx],idx+1,combi,ans);
        solve(candidates,target-candidates[idx],idx,combi,ans);
        combi.pop_back();
        solve(candidates,target,idx+1,combi,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combi;
        solve(candidates,target,0,combi,ans);
        return ans;
    }
};