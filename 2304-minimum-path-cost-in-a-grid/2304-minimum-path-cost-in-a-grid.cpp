class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        
        for(int j=0;j<n;j++) dp[0][j]= grid[0][j];
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    dp[i][j]= min(dp[i][j], grid[i][j]+ dp[i-1][k]+ moveCost[ grid[i-1][k] ][j]);
                }
            }
        }
        return *min_element(begin(dp[m-1]),end(dp[m-1]));
    }
};

// int m = g.size(), n = g[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
//     dp[0] = g[0];
//     for (int i = 1; i < m; ++i)
//         for (int j = 0; j < n; ++j)
//             for (int k = 0; k < n; ++k)
//                 dp[i][k] = min(dp[i][k], g[i][k] + dp[i - 1][j] + moveCost[g[i - 1][j]][k]);
//     return *min_element(begin(dp[m - 1]), end(dp[m - 1]));