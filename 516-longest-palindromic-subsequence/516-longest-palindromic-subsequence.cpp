class Solution {
public:
    int longestPalindromeSubseq(string x) {
        string y = x;
        reverse(y.begin(),y.end());
        int n = x.length();
        
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1]==y[j-1])
                    dp[i][j] = 1+ dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};