class Solution {
private:
    int solve(int k, int n, vector<vector<int>> &dp){
        if(k==1) return dp[k][n]= n;
        if(n<=1) return dp[k][n]= n;
        
        if(dp[k][n]!=-1) return dp[k][n];
        
        int l=0, h= n, temp, mn =INT_MAX;
        
        while(l<=h){
            int mid= l+ ((h-l)>>1);
            
            int left= solve(k-1,mid-1,dp);
            int right= solve(k,n-mid,dp);
            
            temp = 1+max(left,right);
            
            if(left>right)
                h= mid-1;
            else
                l= mid+1;
            
            mn = min(mn, temp);
        }
        return dp[k][n]= mn;
    }
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};
