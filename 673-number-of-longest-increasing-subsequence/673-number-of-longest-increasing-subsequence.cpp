class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1), cnt(n,1);
        
        int mx = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] <nums[i]){
                    
                    if(lis[j]+1 > lis[i]){ //the nums[i] no. must be included here and the lis can be formed in 1 way only
                        lis[i]= lis[j]+1;
                        cnt[i]= cnt[j];
                    }
                    
                    else if(lis[j]+1== lis[i]){//this means nums[j] is giving more ways to form that lis
                        cnt[i]+=cnt[j];
                    }
                }
            }
            mx = max(mx, lis[i]);
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            if(lis[i]==mx) count+=cnt[i];
        }
        return count;
    }
};
