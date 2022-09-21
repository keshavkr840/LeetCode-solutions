class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>  ans;
        long long sum=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)
                sum+= nums[i];
            
        }
        
        for(auto &q: queries){
            int val= q[0];
            int pos= q[1];
            
            if(nums[pos]%2==0)
                sum-= nums[pos];
            
            nums[pos]+=val;
            
            if(nums[pos]%2==0){
                sum+=nums[pos];
            }
            
            ans.push_back(sum);
            
        }
        return ans;
    }
};