class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = size(mat[0]);
        
        vector<vector<int>> ans(m, vector<int>(n,-1));
        
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }   
            }
        }
        
        pair<int,int> dirs[4]= {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            pair<int, int> curr= q.front();
            q.pop();
            for(auto &dir:dirs){
                int x= curr.first+ dir.first;
                int y= curr.second + dir.second;
                
                if(x>=0 && x<m && y>=0 && y<n && ans[x][y]==-1){
                    ans[x][y]= 1+ans[curr.first][curr.second];
                    q.push({x,y});
                }
            }
        }
        
        return ans;
    }
};