class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0, maxs= INT_MIN;
        for(auto n : nums){
            sum+=n;
            if(sum<n)
                sum=n;
            maxs= max(maxs, sum);
        }
        return maxs;
    }
};