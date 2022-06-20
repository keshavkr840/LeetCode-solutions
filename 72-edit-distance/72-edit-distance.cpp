class Solution {
public:
    int minDistance(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        if(m==0|| n==0) return max(m,n);
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0) dp[i][j]= max(i,j);
                
                else if(str1[i-1]== str2[j-1]) 
                    dp[i][j]= dp[i-1][j-1];
                
                else 
                    dp[i][j]= 1+ min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        
        return dp[m][n];
    }
};