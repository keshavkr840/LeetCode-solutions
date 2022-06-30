class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = INT_MAX,sum=0;
        int sz=nums.size();
        for(auto &n:nums){
            sum+=n;
            mn = min(n, mn);
        }
        return (sum- mn*sz);
    }
};