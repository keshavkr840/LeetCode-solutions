class Solution {
private:
    void count(vector<vector<char>>& grid, vector<vector<bool>> &vis, int m, int n, int row, int col){
        if(row<0 || col<0 || row==m || col==n) return;
        
        if(vis[row][col] || grid[row][col]=='0') return;
        
        vis[row][col]= true;
        count(grid, vis, m, n, row, col-1);
        count(grid, vis, m, n, row, col+1);
        count(grid, vis, m, n, row-1, col);
        count(grid, vis, m, n, row+1, col);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m , vector<bool>(n,false));
        
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count(grid, vis, m, n, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};