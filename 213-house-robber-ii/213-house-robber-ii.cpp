class Solution {
private:
    int solve(vector<int> &v){
        int n = v.size();
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=v[0];
        for(int i=2;i<=n;i++){
            dp[i]= max(dp[i-1],dp[i-2]+ v[i-1]);
        }
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        else if (n==2) return max(nums[0], nums[1]);
        
        vector<int> n1= nums;
        n1.pop_back();
        vector<int> n2;
        for(int i=1;i<nums.size();i++)
            n2.push_back(nums[i]);
        
        return max(solve(n1), solve(n2));
    }
};