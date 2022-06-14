class Solution {
public:
    int minPathSum(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        for(int i=1;i<m;i++) dungeon[i][0]+= dungeon[i-1][0];
        for(int j=1;j<n;j++) dungeon[0][j]+= dungeon[0][j-1];
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dungeon[i][j]+=  min(dungeon[i-1][j], dungeon[i][j-1]);
            }
        }
        return dungeon[m-1][n-1];
    }
};