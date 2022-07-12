class Solution {
private:
    vector<bool> map;
    bool solve(vector<int> &nums,int &target, int k, int idx, int sum){
        if(k==0) return true;
        
        if(sum==target) return solve(nums,target, k-1,0, 0);
        
        for(int i=idx;i<nums.size();i++){
            if(map[i] || nums[i]+sum> target) continue;
            
            map[i]= true;
            if(solve(nums, target, k, i+1, sum+nums[i])) return true;
            map[i]= false;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1) return true;
        
        int sum = accumulate(nums.begin(), nums.end(),0);
        int mx = *max_element(nums.begin(), nums.end());
        
        if(sum%k!=0 || mx> (sum/k)) return false;
        
        map.resize(nums.size(),false);
        int target= sum/k;
        
        bool ans = solve(nums,target,k, 0,0 );
        return ans;
    }
};