class Solution {
public:
    int countBits(int n){
        int cnt =0;
        for(int i=31; i>=0 ;i--){
            if(n & (1<<i)) cnt++;
        }
        return cnt;
    }
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> numBits;
        
        for(auto &n: set)
            numBits.push_back(countBits(n));
        
        sort(numBits.begin(), numBits.end());
        
        long long ans=0;
        for(int i=0;i<numBits.size(); i++){
            auto it =  lower_bound(numBits.begin(), numBits.end(), k-numBits[i]);
            ans+=(numBits.end()-it);
        }
        return ans;
    }
};