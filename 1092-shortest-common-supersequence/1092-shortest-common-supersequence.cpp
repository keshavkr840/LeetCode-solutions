class Solution {
public:
    string shortestCommonSupersequence(string x, string y) {
        int m = x.length(), n = y.length();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1]==y[j-1])
                    dp[i][j]= 1+dp[i-1][j-1];
                else 
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        string ans="";
        int i=m, j=n;
        while(i>0 && j>0){
            if(x[i-1]==y[j-1]){
                ans.push_back(x[i-1]);
                --i;--j;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans.push_back(x[i-1]);
                --i;
            }
            else{
                ans.push_back(y[j-1]);
                --j;
            }
        }
        
        while(i>0){
            ans.push_back(x[i-1]);
            --i;
        }
        while(j>0){
            ans.push_back(y[j-1]);
            --j;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};