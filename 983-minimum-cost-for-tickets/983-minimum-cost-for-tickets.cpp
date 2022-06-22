class Solution {
public:
    int dp[365];
    int solve(vector<int>& days, vector<int>& costs, int idx){
        int n = days.size();
        if(idx>=n)  return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int dayCost = costs[0]+ solve(days,costs,idx+1);
        
        int i;
        for(i=idx;i<n;i++) if(days[i]>days[idx]+6) break;
        int weekCost = costs[1] + solve(days,costs, i);
        
        for(i= idx;i<n;i++) if(days[i]>days[idx]+ 29) break;
        int monthCost = costs[2] + solve(days,costs,i);
        
        return dp[idx]= min({dayCost,weekCost, monthCost});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(days, costs, 0);
    }
};

