class Solution {
private:
    
    int findCost(vector<int> &dp, vector<int>& cost, int i){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]= cost[i] + min(findCost(dp,cost,i+1), findCost(dp, cost,i+2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // dp.resize(n);
        vector<int> dp(n,-1);
        // memset(dp,-1,sizeof(dp));
        return min(findCost(dp,cost,0), findCost(dp,cost,1));
    }
};