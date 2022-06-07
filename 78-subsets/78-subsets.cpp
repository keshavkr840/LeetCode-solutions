class Solution {
public:
    void solve(int pos,vector<int>& nums,vector<vector<int>>& ans,  vector<int> &v){
        ans.push_back(v);
        for(int i=pos;i<nums.size();++i){
            v.push_back(nums[i]);
            solve(i+1,nums,ans,v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(0,nums,ans,v);
        return ans;
    }
};