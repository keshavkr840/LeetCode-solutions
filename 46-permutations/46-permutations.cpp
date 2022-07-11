class Solution {
private:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx], nums[i]);
            //after swapping the next index must be idx+1, not i+1, because if we pass i+1, the elememts between idx & i, go unaltered, and they are not included in answer
            solve(nums,idx+1);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};