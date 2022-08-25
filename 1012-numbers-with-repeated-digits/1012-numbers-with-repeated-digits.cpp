class Solution {
public:
    int dp[1<<10][11][2];
    int count(string &num, int mask, int n , bool tight){
        if(n==0) return mask!=0;
        
        if(dp[mask][n][tight]!=-1)
            return dp[mask][n][tight];
        
        int ub = tight?num[num.size()-n]-'0' :9;
        int ans=0;
        
        for(int i=0;i<=ub;i++){
            if(mask & (1<<i)) continue;
                
            if(i==0 && mask==0)
                ans+= count(num, mask, n-1, tight&(i==ub));
            else
                ans+= count(num, mask| (1<<i), n-1, tight&(i==ub));
            
        }
        
        return dp[mask][n][tight]= ans;
        
    }
    int numDupDigitsAtMostN(int n) {
        memset(dp,-1,sizeof(dp));
        int mask=0;
        string num = to_string(n);
        return n- count(num, mask, num.size(),1);
    }
};