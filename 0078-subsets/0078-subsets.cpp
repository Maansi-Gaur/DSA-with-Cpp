class Solution {
public:
 vector<vector<int>> ans;
  void solve(vector<int>& nums, int idx, vector<int>& current) {
    if(idx==nums.size()){
        ans.push_back(current);
        return ;
    }
    
    current.push_back(nums[idx]);
    solve(nums, idx+1, current);

    current.pop_back();
    solve(nums, idx+1, current);
   }

    vector<vector<int>> subsets(vector<int>& nums) {
       
        vector<int> current;
        solve(nums,0,current);
        return ans;
    }
};