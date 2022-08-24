class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        
        unordered_map<int, int> map;
        long long gp=0;
        for(int i=0;i<n;i++){
            gp+= map[nums[i]-i]++;
        }
        return (1LL*(n*(n-1))/2) -gp;
    }
};