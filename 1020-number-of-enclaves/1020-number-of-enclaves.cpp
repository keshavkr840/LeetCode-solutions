class Solution {
private:
    int countEnclaves(vector<vector<int>>& grid, int i, int j){
        if((i==0 || j==0 || i== grid.size()-1|| j== grid[0].size()-1) && grid[i][j]==1)
            return -1;
        
        if(grid[i][j]==0 || grid[i][j]==2) return 0;
        grid[i][j]=2;
        
        
        int a= countEnclaves(grid, i, j-1);
        int b= countEnclaves(grid, i, j+1);
        int c= countEnclaves(grid, i-1, j);
        int d= countEnclaves(grid, i+1, j);
        
        if(a==-1 || b==-1 || c==-1 ||d==-1) return -1;
        else return (1+a+b+c+d);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                int temp= countEnclaves(grid, i, j);
                ans+= temp==-1 ? 0: temp;
            }
        }
        return ans;
    }
};