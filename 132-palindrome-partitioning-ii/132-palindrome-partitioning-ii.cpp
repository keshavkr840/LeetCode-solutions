class Solution {
public:
    bool isPalin(string &s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int solve(vector<vector<int>> &dp, string &s, int i, int j){
        if(i>=j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(isPalin(s,i,j)) return dp[i][j]=0;
        
        int mn = INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalin( s,i,k)){
                int temp = solve(dp, s,k+1,j)+1;
                mn= min(temp, mn);
            }
//             int left = solve(dp, s,i,k);
//             int right = solve(dp, s,k+1,j);
            
//             mn= min(left+right+1,mn);
        }
        return dp[i][j]=mn;
        
    }
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1) );
        return solve(dp, s, 0, n-1);
    }
};