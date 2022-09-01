class Solution {
public:
    void dfs(vector<vector<int>>& heights, int &m , int &n, vector<vector<bool>> &used, int i, int j){
        used[i][j]= true;
        
        if(i>=1 && !used[i-1][j] && heights[i-1][j]>= heights[i][j]) dfs(heights, m, n, used, i-1,j);
        if(j>=1 && !used[i][j-1] && heights[i][j-1]>= heights[i][j]) dfs(heights, m, n, used, i,j-1);
        if(i+1<m && !used[i+1][j] && heights[i+1][j]>= heights[i][j]) dfs(heights, m, n, used, i+1,j);
        if(j+1<n && !used[i][j+1] && heights[i][j+1]>= heights[i][j]) dfs(heights, m, n, used, i,j+1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pa (m, vector<bool>(n, 0)), at(m, vector<bool>(n, 0));

        for(int i=0;i<m;i++){
            dfs(heights, m, n, pa, i, 0);
            dfs(heights, m, n, at, i, n-1);
        }
        
        for(int i=0; i<n;i++){
            dfs(heights, m, n, pa, 0, i);
            dfs(heights, m, n, at, m-1, i);
        }
        
        vector<vector<int >>ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;++j){
                if(pa[i][j] && at[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};