class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(),mx=1;
        vector<pair<int,int>> lis(n,{1,1});
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if( 1+lis[j].first==lis[i].first){
                        lis[i].second+= lis[j].second;
                    }
                    else if(1+ lis[j].first> lis[i].first){
                        lis[i].second= lis[j].second;
                        lis[i].first= 1+ lis[i].first;
                    }
                    mx = max(mx, lis[i].first);
                }
            }
        }
        int ans=0;
        
        for(auto &v: lis){
            if(v.first==mx)
                ans+=v.second;
        }
        return ans;
    }
};