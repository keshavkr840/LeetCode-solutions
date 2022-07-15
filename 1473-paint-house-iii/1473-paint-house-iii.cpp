class Solution {
private:
    long long dp[101][21][101];
    long long solve(vector<int>& houses, vector<vector<int>>& cost, int &m, int &n, int target, int house, int prev){
        if(house==m) return(target==0)?0:INT_MAX;
        if(target<0) return INT_MAX;
        if((m-house)<target) return INT_MAX;
        
        if(dp[house][prev][target] != -1) return dp[house][prev][target];
        
        long long mincost = INT_MAX;
        
        if(houses[house]!=0) 
            mincost = solve(houses, cost, m, n, target-(prev!=houses[house]), house+1,houses[house] );
        else{
            // long long 
            for(int j=0;j<n;j++){
                long long tempcost= solve(houses, cost, m, n,target-(prev!=j+1), house+1, j+1)+ cost[house][j];
                mincost =min(mincost, tempcost);
            }
        }
        return dp[house][prev][target]=mincost;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        long long mx = INT_MAX;
        long long ans=solve(houses,cost,m,n, target, 0,0);
        return (ans>= INT_MAX)?-1: ans;
    }
};