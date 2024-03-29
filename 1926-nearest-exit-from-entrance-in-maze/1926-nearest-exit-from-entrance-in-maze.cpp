class Solution {
private:
    int bfs(vector<vector<char>>& grid, vector<int>& entrance){
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<vector<int>> q;
        q.push(entrance);
        
        grid[entrance[0]][entrance[1]]='+';
        
        pair<int, int> dirs[4]=  {{0,1},{0,-1}, {1,0}, {-1,0}};
        int moves=0;
        while(!q.empty()){
            int l = q.size();
            
            for(int i=0;i<l;i++){
                vector<int> curr= q.front();
                q.pop();

                for(auto &dir: dirs){

                    int x= curr[0]+ dir.first;
                    int y= curr[1]+ dir.second;

                    if((x<0 || y<0 || x==m || y==n)){
                        if(curr[0]==entrance[0] && curr[1]==entrance[1]) continue;
                        return moves;
                    } 
                    else if(grid[x][y]=='.'){
                        grid[x][y]= '+';
                        // cout<<"ok : "<<x<<" "<<y<<" "<<grid[x][y]<<endl;
                        q.push({x, y});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        return bfs(maze, entrance);
        
    }
};