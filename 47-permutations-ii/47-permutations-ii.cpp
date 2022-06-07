class Solution {
public:
     void solve(int pos, vector<int>& nums, set<vector<int>> &s){
        if(pos==nums.size()){
            s.insert(nums);
            return;
        }
        
        for(int i=pos;i<nums.size();i++){
            swap(nums[i],nums[pos]);
            solve(pos+1,nums,s);
            swap(nums[i],nums[pos]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        solve(0,nums,s);

        vector<vector<int>> ans;
        
        for(auto v: s){
            ans.push_back(v);
        }
        return ans;
    }
};