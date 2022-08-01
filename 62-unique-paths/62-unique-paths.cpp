class Solution {
private:
    int mod =2e9;
    int dp[101][101];
    int ways(int m, int n){
        if(m==0 && n==0) return dp[0][0]= 1;
        if(m<0 || n<0) return 0;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        return dp[m][n]= ( ways(m,n-1)%mod + ways(m-1,n)%mod)%mod;
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp,-1, sizeof(dp));
        return ways(m-1,n-1);
    }
};