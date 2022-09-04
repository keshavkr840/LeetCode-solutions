class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res=0, ans=0, n = nums.size();
        int i=0;
        
        for(int j =0;j<n;j++){
            while(res & nums[j])
                res^=nums[i++];
            res|= nums[j];
            ans = max(ans, j-i+1);
        }
        return ans;
        
    }
};