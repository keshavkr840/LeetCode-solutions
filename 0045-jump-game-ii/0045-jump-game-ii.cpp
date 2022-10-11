class Solution {
public:
    int jump(vector<int>& nums) {
        //https://www.youtube.com/watch?v=vBdo7wtwlXs&list=PLamzFoFxwoNgG0Q5rqfTY6ovWSTAC9mbz&index=2&ab_channel=IDeserve
        int n = nums.size();
        if(n==1) return 0;
        vector<int> dp(n,n+1);
        dp[0]=0;
        
        for(int i=0;i<n;i++){
            for(int val=1; val<=nums[i] ; val++){
                if(i+val==n-1) return 1+ dp[i];
                
                dp[i+val]=min(dp[i+val],1 + dp[i]);
            }
        }
        
        return dp[n-1];
    }
};