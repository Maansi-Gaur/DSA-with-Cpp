class Solution {
public:
    void solve (vector<int>& nums, int idx, vector<int>&per,vector<vector<int>>&ans ){

        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i= idx; i<nums.size(); i++){

            swap(nums[idx],nums[i]);
            solve(nums,idx+1,per,ans);
            swap(nums[idx],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>per;
        solve(nums,0,per,ans);
        return ans;
    }
};