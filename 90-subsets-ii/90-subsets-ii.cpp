class Solution {
public:
    void solve(int i, vector<int> &nums, set<vector<int>> &s, vector<int> &curr){
        if(i==nums.size()){
            s.insert(curr);
            return;
        }
        solve(i+1, nums, s, curr);
        curr.push_back(nums[i]);
        solve(i+1, nums, s, curr);
        curr.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<int> curr;
        solve(0, nums, s, curr);
        
        vector<vector<int>> ans; 
        for(auto v: s){
           ans.push_back(v);
        }
        return ans;
    }
};