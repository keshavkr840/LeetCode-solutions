class Solution {
private:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, vector<int>& multi, int l, int r, int i){
        if(i==multi.size())
            return 0;
        
        if(dp[l][i]!=INT_MIN) return dp[l][i];
        
        int left= solve(nums, multi, l+1, r, i+1)+ nums[l]*multi[i];
        int right= solve(nums, multi, l, r-1, i+1)+ nums[r]* multi[i];
        
        return dp[l][i]= max(left, right);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        int n = nums.size();
        int m = multi.size();
        dp.resize(m+1, vector<int>(m+1, INT_MIN));
        return solve(nums, multi, 0, n-1, 0);
    }
};