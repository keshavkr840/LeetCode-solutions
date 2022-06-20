class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int l=0, r=0;
        int ans=INT_MAX;
        while(r<nums.size()){
            sum+= nums[r++];
            while(sum>= target){
                sum-= nums[l++];
                ans= min( ans, r-l+1);
            }
        }
        return (ans==INT_MAX)? 0: ans;
    }
};