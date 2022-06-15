class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[m-1][n-1]==1 || grid[0][0]==1) return 0;
        
        int dp[m][n];
        dp[0][0]=1;
        
        int flag =1;
        for(int i=1;i<m;i++){
            if(grid[i][0]==1) flag = 0;
            dp[i][0]=1* flag;
        }
        
        flag =1;
        for(int j=1;j<n;j++){
            if(grid[0][j]==1) flag =0;
            dp[0][j]= 1* flag;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1)
                    dp[i][j]=0;
                
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};