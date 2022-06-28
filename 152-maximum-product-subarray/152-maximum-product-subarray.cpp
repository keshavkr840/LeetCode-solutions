class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=1, mn=1, ans=INT_MIN;
        
        for(auto &n: nums){
            if(n<0)
                swap(mx,mn);
            
            mx = max(n, mx*n);
            mn = min(n, mn*n);
            
            ans= max(ans,mx);
        }
        return ans;
    }
};