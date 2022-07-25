class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a= lower_bound(nums.begin(), nums.end(), target)- nums.begin();
        if(a==nums.size()) return {-1,-1};
        int b = -1+ upper_bound(nums.begin(), nums.end(), target)- nums.begin();
        if(b<a) return {-1, -1};
        
        return {a,b};
    }
};