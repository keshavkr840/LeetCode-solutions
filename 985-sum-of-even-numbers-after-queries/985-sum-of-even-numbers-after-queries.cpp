class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> even(n,0), ans;
        long long sum=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                sum+= nums[i];
                even[i]=1;
            }
        }
        // cout<<sum<<endl;
        
        for(auto &q: queries){
            int val= q[0];
            int pos= q[1];
            
            if(even[pos])
                sum-= nums[pos];
            
            nums[pos]+=val;
            
            if(nums[pos]%2==0){
                sum+=nums[pos];
                even[pos]=1;
            }
            else
                even[pos]=0;
            
            ans.push_back(sum);
            
        }
        return ans;
    }
};