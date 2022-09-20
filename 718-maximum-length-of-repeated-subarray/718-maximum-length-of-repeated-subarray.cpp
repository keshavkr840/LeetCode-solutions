class Solution {
private:
    int dp[1001][1001];
    int mx=0;
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j){
        
        if(i==nums1.size() || j==nums2.size() )
            return dp[i][j]= 0;
        
        else if(dp[i][j]!=-1)
            return dp[i][j];
        
        solve(nums1, nums2, i+1, j);
        solve(nums1, nums2, i, j+1);
        
        if(nums1[i]==nums2[j])
            dp[i][j]= 1+ solve(nums1, nums2, i+1, j+1) ;
        else
            dp[i][j]=0;
        
        mx= max(mx, dp[i][j]);
        
        return dp[i][j];
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        solve(nums1, nums2, 0,0);
        return mx;
    }
};