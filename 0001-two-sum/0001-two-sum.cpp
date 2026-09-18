class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n= nums.size();
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            int more= target-nums[i];
            if(mpp.find(more)!=mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[more]);
            }else{
               mpp[nums[i]]=i;
            }
        }
        return ans;
    }
};