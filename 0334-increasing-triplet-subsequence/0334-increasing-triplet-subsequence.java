class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<long> left(n,0), right(n,0);
        
        long mn = INT_MAX+1L;
        for(int i=0;i<n;i++){
            left[i]=mn;
            if(nums[i]<mn)
                mn = nums[i];
        }
        
        long mx= INT_MIN-1L;
        for(int i=n-1;i>=0;i--){
            right[i]=mx;
            if(nums[i]> mx)
                mx= nums[i];
            if(left[i]< nums[i] && nums[i]< right[i])
                return true;
        }
        return false;
    }
};