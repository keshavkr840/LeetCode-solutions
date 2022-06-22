class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1, string &s2, int m , int n, int ans){
        if(m==0){
            for(int i=n;i>0;i--)
                ans+=(int) s2[i-1];
            return dp[m][n]= ans;
        }
        if(n==0){
            for(int i=m;i>0;i--)
                ans+=(int) s1[i-1];
            return dp[m][n]= ans;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(s1[m-1]==s2[n-1]) return dp[m][n]= solve(s1,s2,m-1,n-1,ans);
        else
            return dp[m][n]= min( (int)s1[m-1]+ solve(s1,s2,m-1,n,ans),(int)s2[n-1]+ solve(s1,s2,m,n-1,ans));
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return solve(s1, s2, s1.length(), s2.length(),0);
    }
};