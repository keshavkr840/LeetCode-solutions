class Solution {
private:
    bool isClosed(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i==grid.size() || j == grid[0].size())
            return false;
        
        if(grid[i][j]==1) return true;
        
        grid[i][j]=1;
        bool ans= true;
        ans &= isClosed(grid, i, j-1);
        ans &= isClosed(grid, i, j+1);
        ans &= isClosed(grid, i-1, j);
        ans &= isClosed(grid, i+1, j);
        
        return ans;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    if(isClosed(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};