class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int mx=1, start=0;
        
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]= 1;
                mx=2;
                start= i;
            }
        }
        
        for(int k=3;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                int end=i+k-1;
                
                if(s[i]==s[end] && dp[i+1][end-1]){
                    dp[i][end]=1;
                    
                    if(k>mx){
                        mx= k;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start, mx);
    }
};