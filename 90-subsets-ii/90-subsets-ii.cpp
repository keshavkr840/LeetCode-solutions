class Solution {
private:
    vector<vector<int>> ans;
    void solve(vector<int> & nums, vector<int> & temp, int idx ){
        ans.push_back(temp);
        
        for(int i=idx; i<nums.size();i++){
            if(i> idx && nums[i]== nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums, temp, i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums,temp,0);
        return ans;
    }
};