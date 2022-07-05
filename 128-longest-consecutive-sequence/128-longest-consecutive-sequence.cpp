class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans= 0;
        
        for(auto & n : nums){
            if(set.find(n-1)==set.end()){
                int curr= n, tempans=1;
                
                while(set.find(curr+1)!= set.end()){
                    curr++;
                    tempans++;
                }
                ans= max(ans, tempans);
            }
        }
        return ans;
    }
};