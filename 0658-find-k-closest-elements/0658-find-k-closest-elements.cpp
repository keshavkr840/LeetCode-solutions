#define nums arr
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        auto it = lower_bound(arr.begin(), arr.end(), x)-arr.begin();
        
        int l= it-1, h = it;
        vector<int> ans;
        while(k-- >0){
            if(l<0)
                ans.push_back(nums[h++]);
            
            else if(h==n || abs(x-nums[l])<=abs(x-nums[h]))
                ans.push_back(nums[l--]);
            else
                ans.push_back(nums[h++]);
                
        }
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};