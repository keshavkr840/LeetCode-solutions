class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> set(nums.begin(), nums.end());
        
        vector<int> bitfreq(32,0);
        for(auto it: set){
            
            int bits= __builtin_popcount(it);
            bitfreq[bits]++;
            
        }
        
        long long ans=0;
        for(int i=0;i<32;i++){
            
            
            if(bitfreq[i]==0) continue;
            // cout<<i<<" : "<<bitfreq[i]<<" : "<<max(0,k-i)<<"  :  ans =  ";
            for(int j= max(0,k-i); j<32; j++){
                ans+= (1LL *bitfreq[i]*bitfreq[j]);
            }
            // cout<<ans<<endl;
        }
        
        return ans;
    }
};