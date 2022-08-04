class Solution {
private:
    bool isClosed(vector<vector<int>>& grid, int i, int j){
        if((i==0 || j==0 || i== grid.size()-1 || j== grid[0].size()-1) && grid[i][j]==0)
            return false;
        if(grid[i][j]==1) return true;
        grid[i][j]=1;
        
        bool ans= true;
        ans &= isClosed(grid, i,j-1);
        ans &= isClosed(grid, i,j+1);
        ans &= isClosed(grid, i-1,j);
        ans &= isClosed(grid, i+1,j);
        
        return ans;
        
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++){
                if(grid[i][j]==0)
                    if(isClosed(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};