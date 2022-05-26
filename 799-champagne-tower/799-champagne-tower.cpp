class Solution {
public:
    double dp[101][101];
    double solve(int & poured, int row, int col){
        if(row<0 || row<col || col<0) return 0.0;
        if(dp[row][col]!=-1) return dp[row][col];
        if (row== 0 && col ==0) return dp[0][0]= poured;
        
        double left = (solve(poured,row-1, col-1)-1)/2.0;
        double right = (solve(poured, row-1, col)-1)/2.0;
        
        return dp[row][col]= ((left>0) ? left : 0.0) + ((right>0)? right :0.0);
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        fill_n(&dp[0][0], 101*101,-1.0);
        double ans = solve(poured, query_row, query_glass);
        return min(1.00, ans);
    }
};