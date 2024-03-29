class Solution {
    int dp[101][101];
    bool solve(string &a, string &b, string &c, int i, int j, int k){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==a.size())
            return dp[i][j]= b.substr(j).compare(c.substr(k))==0 ;
        else if(j==b.size())
            return dp[i][j]= (a.substr(i).compare(c.substr(k))==0);
        
        else if(a[i]==c[k] && b[j]==c[k])
            return dp[i][j]= solve(a,b,c, i+1, j, k+1) || solve(a,b,c,i, j+1, k+1);
        else if(a[i]==c[k])
            return dp[i][j]= solve(a,b,c, i+1, j, k+1);
        else if(b[j]==c[k])
            return dp[i][j]= solve(a,b,c, i, j+1, k+1);
        return dp[i][j]= false;
    }
public:
    bool isInterleave(string a, string b, string c) {
        if(a.length()+ b.length()!=c.length()) return false;
        memset(dp, -1, sizeof(dp));
        
        return solve(a, b,c, 0, 0, 0);
    }
};