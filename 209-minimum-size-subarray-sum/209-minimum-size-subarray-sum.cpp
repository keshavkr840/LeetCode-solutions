class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n+1,0);
        
        for(int i=1;i<=n;i++)
            sum[i]= sum[i-1]+ nums[i-1];
        
        int ans= n+1;
        for(int i=n; i>=0 && sum[i]>= target;i--){
            auto it = upper_bound(sum.begin(), sum.end(), sum[i]-target);
            int j = it- sum.begin();
            ans= min(ans, i-j+1);
        }
        return (ans==n+1)?0:ans;
    }
};