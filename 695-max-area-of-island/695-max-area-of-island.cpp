class Solution {
private:
    int maxArea(vector<vector<int>>& grid, vector<vector<bool>> &vis, int &m, int &n, int row, int col){
        if(row<0 || col<0 || row>=m || col>=n || vis[row][col] || grid[row][col]==0) return 0;
        
        // int currArea=0;
        // if(grid[row][col]==1) currArea++;
        vis[row][col] = true;
        
        int currArea = maxArea(grid, vis, m, n, row, col-1) + maxArea(grid, vis, m, n, row, col+1) + maxArea(grid, vis, m, n, row-1, col) + maxArea(grid, vis, m, n, row+1, col);
        
        return 1+ currArea;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        int mx =0;
        for(int i=0;i<m; i++){
            for(int j=0;j<n; j++){
                if(grid[i][j]==1 && !vis[i][j])
                    mx = max(mx, maxArea(grid, vis, m, n, i, j));
            }
        }
        
        return mx;
    }
};