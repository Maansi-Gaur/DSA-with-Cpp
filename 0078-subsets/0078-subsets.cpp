class Solution {
public:
 
  void solve(vector<int>& nums, int idx, vector<int>& current,vector<vector<int>> &ans) {
    if(idx==nums.size()){
        ans.push_back(current);
        return ;
    }
    
    current.push_back(nums[idx]);
    solve(nums, idx+1, current,ans);

    current.pop_back();
    solve(nums, idx+1, current,ans);
   }

    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
        vector<int> current;
        solve(nums,0,current,ans);
        return ans;
    }
};