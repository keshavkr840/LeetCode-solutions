class Solution {
public:
    int helper(vector<int> &nums, vector<int> &dp, int i){
        if(i>=nums.size()) return true;
        
        if(dp[i]!=-1) return dp[i];
        
        if(i+1< nums.size() && nums[i+1]==nums[i]){
            if(helper(nums,dp, i+2)) return true;
            if(i+2<nums.size() && nums[i+2]== nums[i]){
                if(helper(nums,dp,i+3)) return true;
            }
        }
        
        else if(i+1< nums.size() && nums[i+1]==1+ nums[i]){
            // if(helper(nums,dp, i+2)) return true;
            if(i+2<nums.size() && nums[i+2]== 2+ nums[i]){
                if(helper(nums,dp,i+3)) return true;
            }
        }
        
        return dp[i]= false;
    }
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums, dp,0);
    }
};