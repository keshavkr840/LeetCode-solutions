class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int median= nums[n/2];
        int ans=0;
        
        for(int i=0;i<n/2;i++)
            ans+=(nums[n-1-i]-nums[i]);
        return ans;
    }
};