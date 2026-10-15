class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        auto first = lower_bound(nums.begin(),nums.end(),target);
        auto second = upper_bound(nums.begin(),nums.end(),target);
        if(first==nums.end()||*first!=target){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{ans.push_back(first-nums.begin());
        ans.push_back(second-nums.begin()-1);}
        return ans;
    }
};