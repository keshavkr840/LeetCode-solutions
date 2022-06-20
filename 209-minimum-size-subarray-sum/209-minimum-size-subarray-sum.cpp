class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0, l=0, r=0;
        int n = nums.size();
        int ans=n+1;
        while(r<n){
            sum+= nums[r++];
            while(sum>= target){
                ans= min( ans, r-l);
                sum-= nums[l++];
            }
        }
        return (ans==n+1)? 0: ans;
    }
};