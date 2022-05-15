#define INF INT_MAX-1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        int dp[n+1][amount +1];
        memset(dp, 0, sizeof(dp));
        
        for(int j=1;j<=amount;j++){ 
            dp[0][j] = INF;
            if(j%coins[0]==0){
                dp[1][j]= j/coins[0];
            }
            else dp[1][j]= INF;
        }
        
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j)
                    dp[i][j] = min(dp[i-1][j], 1+ dp[i][j-coins[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (dp[n][amount]==INF) ? -1 : dp[n][amount];
    }
};