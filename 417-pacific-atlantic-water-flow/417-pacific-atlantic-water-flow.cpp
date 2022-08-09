class Solution {
public:
    void dfs(vector<vector<int>>& A, vector<vector<bool>>& vis, int i, int j){
        if(vis[i][j]) return;
        
        vis[i][j]= true;
        
        if(j>=1 && A[i][j-1]>=A[i][j]) dfs(A, vis, i, j-1);
        if(j+1< size(A[0]) && A[i][j+1]>= A[i][j]) dfs(A, vis, i, j+1);
        if(i>=1 && A[i-1][j]>= A[i][j]) dfs(A, vis, i-1, j);
        if(i+1<size(A) && A[i+1][j]>=A[i][j]) dfs(A, vis, i+1,j);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& A) {
        vector<vector<int>> ans;
        int m = size(A);
        int n = size(A[0]);
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false)), atlantic(m, vector<bool>(n, false));
        
        for(int i=0;i<m;i++){
            dfs(A, pacific,i,0);
            dfs(A, atlantic,i, n-1);
        }
        
        for(int j=0;j<n;j++){
            dfs(A, pacific, 0, j);
            dfs(A, atlantic, m-1, j);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int m, n;
// 	// denotes cells reachable starting from atlantic and pacific edged cells respectively
//     vector<vector<bool> > atlantic, pacific;
// 	vector<vector<int> > ans;    
//     vector<vector<int> > pacificAtlantic(vector<vector<int>>& mat) {
//         if(!size(mat)) return ans;
//         m = size(mat), n = size(mat[0]);
//         atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
// 		// perform dfs from all edge cells (ocean-connected cells)
//         for(int i = 0; i < m; i++) dfs(mat, pacific, i, 0), dfs(mat, atlantic, i, n - 1);
//         for(int i = 0; i < n; i++) dfs(mat, pacific, 0, i), dfs(mat, atlantic, m - 1, i);             
//         return ans;
//     }
//     void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j){        
//         if(visited[i][j]) return;
//         visited[i][j] = true;
// 		// if cell reachable from both the oceans, insert into final answer vector
//         if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});    
// 		// dfs from current cell only if height of next cell is greater
// /*⬇️*/  if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j); 
// /*⬆️*/  if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
// /*➡️*/  if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1); 
// /*⬅️*/  if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);
//     }
// };
