class Solution {
public:
    int dp[1001][1001];
    int lcs(string &a, string &b, int m,int n){
        if(m==0 ||n==0) return 0;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(a[m-1]==b[n-1])
            return dp[m][n]= 1+ lcs(a,b,m-1,n-1);
        else
            return dp[m][n]= max(lcs(a,b,m-1,n),lcs(a,b, m, n-1));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        memset(dp,-1, sizeof(dp));
        return lcs(text1, text2,m,n);
    }
};