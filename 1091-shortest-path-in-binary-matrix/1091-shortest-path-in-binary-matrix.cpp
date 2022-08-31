class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] || grid[m-1][n-1]) return -1;
        if(m==1 && n==1) return 1;
        
        queue<vector<int>> q;
        q.push({0,0,1});
        grid[0][0]=-1;
        pair<int, int> dirs[8]= {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        while(!q.empty()){
            auto curr= q.front();
            q.pop();
            grid[curr[0]][curr[1]]=-1;
            
            for(auto &dir: dirs){
                int x= dir.first + curr[0];
                int y= dir.second + curr[1];
                
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0){
                    grid[x][y]=-1;
                    if(x==m-1 && y==n-1) return 1+ curr[2];
                    q.push({x,y,1+ curr[2]});
                }
            }
        }
        return -1;
    }
};