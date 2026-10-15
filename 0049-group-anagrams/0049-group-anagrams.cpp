class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>> mpp;
        int n= strs.size();
        for(int i=0; i<n; i++){
            string key= strs[i];
            sort(key.begin(),key.end());
           mpp[key].push_back(strs[i]);
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};