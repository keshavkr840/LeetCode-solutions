class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] || grid[m-1][n-1]) return -1;
        if(m==1 && n==1) return 1;
        
        queue<vector<int>> q;
        vector<vector<int>> shortest(m, vector<int>(n,INT_MAX));
        q.push({0,0,1});
        
        pair<int, int> dirs[8]= {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        int dist=INT_MAX;
        
        while(!q.empty()){
            vector<int> curr=q.front();
            q.pop();
            
            for(auto &dir: dirs){
                int x= curr[0]+ dir.first;
                int y= curr[1]+ dir.second;
                
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0 && shortest[x][y]>curr[2]+1){
                    shortest[x][y]=min(shortest[x][y],curr[2]+1);
                    q.push({x,y,shortest[x][y]});
                }
            }
        }
        
        return shortest[m-1][n-1]==INT_MAX? -1: shortest[m-1][n-1];
    }
};