class Solution {
public:
    pair<int, int> dirs[4]= {{1,0},{-1,0},{0,1},{0,-1}};
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j])
                    q.push({i,j});
            }
        }
        
        if(q.size()==m *n) return -1;
        int dist= 0;
        
        while(!q.empty()){
            pair<int, int> curr= q.front();
            q.pop();
            
            for(auto &dir:dirs){
                int x= curr.first+ dir.first;
                int y = curr.second+ dir.second;
                
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0){
                    q.push({x,y});
                    grid[x][y]= grid[curr.first][curr.second]+1;
                    dist = max(dist, grid[x][y]);
                }
            }
        }
        return dist-1;
    }
};