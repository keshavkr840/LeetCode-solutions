class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> dp(n,{1,1});
        
        int mx=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(nums[j] <nums[i]){
                    if(dp[j].first +1 > dp[i].first){
                        dp[i].first = dp[j].first+1;
                        dp[i].second = dp[j].second;
                    }
                    else
                        if(dp[j].first +1 == dp[i].first){
                            dp[i].second += dp[j].second;
                        }
                }
            }
            mx = max(mx, dp[i].first);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(mx==dp[i].first) ans+=dp[i].second;
        }
        
        return ans;
    }
};