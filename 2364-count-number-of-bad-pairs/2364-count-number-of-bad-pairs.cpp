class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        
        unordered_map<int, int> map;
        long long gp=0;
        for(int i=0;i<n;i++){
            if(map.find(nums[i]-i)!= map.end()){
                gp+= map[nums[i]-i]++;
            }
            else map[nums[i]-i]=1;
        }
        return (1LL*(n*(n-1))/2) -gp;
    }
};