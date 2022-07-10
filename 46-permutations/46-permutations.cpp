class Solution {
private:
    unordered_set<int> set;
    vector<vector<int>> ans;
    
    void solve(vector<int> &nums, vector<int> & temp){
        
        if(temp.size()==nums.size()){ 
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(set.find(nums[i])!=set.end()) continue;
            
            set.insert(nums[i]);
            temp.push_back(nums[i]);
            solve(nums,temp);
            set.erase(set.find(nums[i]));
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // for(auto &n: nums) set.insert(n);
        vector<int> temp;
        solve(nums, temp);
        return ans;
    }
};