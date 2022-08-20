class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n = v.size();
        if(n==1) return v;
        
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        
        for(auto &n: v){
            if(ans.empty()|| ans.back().back()< n.front()){
                ans.push_back(n);
            }
            else{
                ans.back().back()= max(ans.back().back(), n.back());
            }
        }
        return ans;
    }
};