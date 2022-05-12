class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        s = abs(s);
        int n = nums.size();
        
        int numZero=0, sum=0;
        for(auto &n : nums){
            sum+=n;
            if(n==0)++numZero;
        }
        
        if(s>sum || (sum-s)%2!=0) return 0;
        int k = (sum-s)/2;
        
        int dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(nums[i-1]>j || nums[i-1]==0)
                     dp[i][j] = dp[i-1][j];
                
                else
                   dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
        }
        
        return (int)pow(2,numZero)*dp[n][k];
    }
};