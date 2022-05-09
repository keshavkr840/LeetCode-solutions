class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int, int> map;
        int sum =0;
        map[sum]++;
        for(auto n: nums){
            sum+=n;
            
            if(map.find(sum-k)!= map.end())
                ans+= map[sum-k];
            
            map[sum]++; 
        }
        return ans;
    }
};