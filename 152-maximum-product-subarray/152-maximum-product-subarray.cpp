class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx,mn,ans, n = nums.size();
        mx= mn =ans= nums[0];
        
        for(int i=1;i<n;i++){
            int temp= mx;
            mx= max({nums[i], nums[i]*mx, nums[i]*mn});
            mn = min({nums[i], nums[i]*temp, nums[i]*mn});
            ans= max(ans,mx);
        }
        return ans;
    }
};