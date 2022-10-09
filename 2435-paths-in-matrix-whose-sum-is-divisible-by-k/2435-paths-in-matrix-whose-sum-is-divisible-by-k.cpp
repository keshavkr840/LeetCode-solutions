class Solution {
private:
    int mod= 1e9+7, m ,n, k;
    int solve(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int i, int j , int rem){
        if(i==m || j==n)
            return 0;
        rem= (rem+ grid[i][j])%k;
        
        if(i==m-1 && j==n-1){
            if(rem==0) return 1;
            else return 0;
        }
        
        if(dp[i][j][rem]!=-1)
            return dp[i][j][rem];
        
        long long ans=0;
        ans+= solve(grid, dp, i+1, j, rem)%mod+ solve(grid, dp, i, j+1, rem)%mod;
        
        return dp[i][j][rem]= ans%mod;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m= grid.size(), n= grid[0].size(), this->k= k;
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(k,-1)));
        
        return solve(grid, dp, 0, 0, 0);
    }
};