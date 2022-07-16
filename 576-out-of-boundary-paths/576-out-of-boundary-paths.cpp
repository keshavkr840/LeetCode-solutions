class Solution {
private:
    long long dp[51][51][51];
    int mod = 1e9+7;
    long long solve(int &m, int &n, int remMove,  int row, int col){
        if(row<0 || row==m || col<0 || col==n) return 1;
        if(remMove==0) return 0;
        if(dp[row][col][remMove]!=-1) return dp[row][col][remMove];
        
        long long ans= solve(m, n, remMove-1,row-1, col) + solve(m, n, remMove-1,row+1, col) + solve(m, n, remMove-1,row, col-1)+ solve(m, n, remMove-1,row, col+1);
        return dp[row][col][remMove] = ans%mod;
        
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        long long ans= solve(m, n, maxMove, startRow, startColumn);
        return ans%mod;
    }
};