class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(i+nums[i],mx);
            if(mx>=n-1) return true;
            if(mx<=i) return false;
        }
        return true;
    }
};