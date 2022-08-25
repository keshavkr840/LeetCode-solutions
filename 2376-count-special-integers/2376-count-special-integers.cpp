class Solution {
public:
    int dp[1<<10][11][2];
    int count(string &num, int mask, int n, bool tight){
        if(n==0){
            return mask!=0;
        }
        
        if(dp[mask][n][tight]!=-1) return dp[mask][n][tight];
        
        int ub = tight? num[num.size()-n]-'0': 9;
        int ans=0;
        
        for(int i=0;i<=ub;i++){
            if(mask & (1<<i)) continue;
            if(i==0 && mask==0)
                ans+= count(num, mask, n-1, tight&(i==ub));
            else
                ans+= count(num, mask|(1<<i), n-1, tight&(i==ub));
        }
        return dp[mask][n][tight]= ans;
    }
    int countSpecialNumbers(int n) {
        int mask=0;
        memset(dp,-1,sizeof(dp));
        string num= to_string(n);
        return count(num, mask, num.size(),true);
    }
};
// if((mask&(1<<dig))==0){
                
//                 if(mask == 0 && dig == 0)
//                     count+=helper(num,n-1,mask,tight&(dig==ub));
//                 else
//                     count+=helper(num,n-1,(mask|(1<<dig)),tight&(dig==ub));
//             }
// class Solution {
// public:
//     int dp[11][2][(1<<11)-1];
//     int helper(string &num,int n,int mask,bool tight){
//         if(n==0) return mask!=0;
//         if(dp[n][tight][mask]!=-1) return dp[n][tight][mask];
//         int count =0;
//         int ub = tight?(num[num.length()-n]-'0'):9;
//         for(int dig =0;dig<=ub;dig++){
//             if((mask&(1<<dig))==0){
//                 count+=helper(num,n-1,(mask|(1<<dig)),tight&(dig==ub));
//             }
//         }
//         return dp[n][tight][mask] = count;
//     }
//     int countSpecialNumbers(int n) {
//         string s = to_string(n);
//         int x = s.length();
//         memset(dp,-1,sizeof(dp));
//         return helper(s,x,0,1);
//     }
// };