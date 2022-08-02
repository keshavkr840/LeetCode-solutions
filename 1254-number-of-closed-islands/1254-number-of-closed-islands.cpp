class Solution {
private:
    bool isClosed(vector<vector<int>>& grid, vector<vector<bool>> &vis, int &m , int &n, int i, int j){
        if((i==0 || j==0 || i==m-1 || j==n-1) && (grid[i][j]==0)) return false;
        
        
        vis[i][j]= true;
        if(grid[i][j]) return true;
        
        bool ans= true;
        if(!vis[i][j-1]) ans= ans& isClosed(grid, vis, m, n, i, j-1);
        if(!vis[i][j+1]) ans= ans& isClosed(grid, vis, m, n, i, j+1);
        if(!vis[i-1][j]) ans= ans& isClosed(grid, vis, m, n, i-1, j);
        if(!vis[i+1][j]) ans= ans& isClosed(grid, vis, m, n, i+1, j);
        
        return ans;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        
        int ans=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(!vis[i][j] && grid[i][j]==0)
                    ans+= isClosed(grid, vis, m, n, i, j);
            }
        }
        return ans;
    }
};