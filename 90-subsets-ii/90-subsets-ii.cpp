class Solution {
private:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int> & temp, int i){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, temp, i+1);
        temp.pop_back();
        while(i+1<nums.size() && nums[i+1]==nums[i]) i++;
        
        solve(nums, temp, i+1);
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums,temp,0);
        return ans;
    }
};