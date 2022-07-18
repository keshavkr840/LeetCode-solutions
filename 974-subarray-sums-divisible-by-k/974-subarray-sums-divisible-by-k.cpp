class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int , int> map;
        
        int sum=0,ans=0;
        map[sum]++;
        
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            
            int rem = sum%k;
            if(rem<0) rem+=k;
            if(map.find(rem)!= map.end())
                ans+=map[rem];
            
            map[rem]++;
        }
        return ans;
    }
};