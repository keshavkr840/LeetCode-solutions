class Solution {
public:
    //bitmasking
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        set<string> s;
        
        int k = 1<<n;
        for(int i=0;i<k;i++){
            vector<int> v;
            string str;
            for(int j=0;j<n;j++){
                
                if(1 & (i>>j)){
                    str+=to_string(nums[j]);
                    v.push_back(nums[j]);
                }
            }
            
            if(s.find(str)== s.end()){
                s.insert(str);
                ans.push_back(v);
            }
        }
        return ans;
    }
};
