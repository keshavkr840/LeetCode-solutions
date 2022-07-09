class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        for(int i=0;i<n;i++){
            
            while(!dq.empty() && dq.front()<i-k)
                dq.pop_front();
            
            int curr= nums[i]+ (dq.empty()? 0: nums[dq.front()]);
            
            nums[i]= curr;
            
            while(!dq.empty() && nums[dq.back()]<= curr)
                dq.pop_back();
            
            dq.push_back(i);
        }
        return nums[n-1];
    }
};