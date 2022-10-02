class Solution {
private:
    int mod= 1e9+7;
    int dp[31][1001];
    int solve(int i, int&k, int&n, int sum, int &target){
        if(i==n){
            if(sum== target)return 1;
            else return 0;
        }
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        if((target-sum)> (n-i)*k || (target-sum)<(n-i) ) return 0;
        
        long long ans=0;
        for(int j=1;j<=k;j++){
            ans+= (solve(i+1, k, n, sum+j, target))%mod;
        }
        
        return  dp[i][sum]= ans%mod;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(0, k, n, 0, target);
    }
};