class Solution {
public:
    int check(vector<int>& nums, int idx, vector<int> &used, int currsum, int & target,int k){
        if(k==1) return true;
        if(currsum== target)
            return check(nums, 0, used, 0, target, k-1);
        
        for(int i=idx;i<nums.size();i++){
            if(used[i]) continue;
            if(used[i] || nums[i]+currsum> target) break;
            
            used[i]= true;
            if(check(nums, i+1, used, currsum+nums[i], target, k))
                return true;
            used[i]= false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum= accumulate(nums.begin(), nums.end(),0);
        int mx = *max_element(nums.begin(), nums.end());
        
        if(sum%k!=0 || mx> sum/k) return false;
        sort(nums.begin(), nums.end());
        
        int target= sum /k;
        vector<int> used(size(nums), false);
        
        if(check(nums, 0, used, 0, target, k)) return true;
        return false;
    }
};
