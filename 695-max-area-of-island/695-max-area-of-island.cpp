class Solution {
private:
    int solve(vector<vector<int>>& grid, vector<vector<bool>>& seen, int &m, int& n, int i, int j){
        if( i<0 || i>=m || j<0 || j>=n || seen[i][j] || !grid[i][j]) return 0;
        
        seen[i][j]= true;
        int area = solve(grid, seen, m, n, i-1, j) + solve(grid,seen, m, n, i+1,j) +                                    solve(grid,seen,m, n, i,j-1 ) + solve(grid, seen, m, n, i, j+1);
        
        return 1+ area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n,false));
        
        int ans= 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( ! grid[i][j] || seen[i][j]) continue;
                int currans= solve(grid, seen, m, n,  i,j);
                ans = max(ans, currans);
            }
        }
        return ans;
    }
};