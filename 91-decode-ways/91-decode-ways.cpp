class Solution {
public:
    int dp[101];
    int solve(string &s, int &n, int i){
        
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        
        if(i+1<n &&( s[i]<='1'|| (s[i]=='2' && s[i+1]<='6')) ){
            ans= solve(s, n, i+1) + solve(s, n, i+2);   
        } 
        
        else
            ans= solve(s, n, i+1);
        
        return dp[i]= ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s, n, 0);
    }
};