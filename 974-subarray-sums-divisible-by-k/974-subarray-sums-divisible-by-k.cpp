class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0, rem=0, ans=0;
        unordered_map<int, int> map;
        map[rem]++;
        
        for(auto &n : nums){
            sum+=n;
            rem = sum%k;
            
            if(rem<0) rem+=k;
            
            if(map.find(rem)!= map.end()){
                ans+=map[rem];
            }
            map[rem]++;
        }
        return ans;
    }
};