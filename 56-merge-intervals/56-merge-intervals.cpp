class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        
        for(auto &v: intervals){
            if(ans.empty()|| v[0]> ans.back()[1])
                ans.push_back(v);
            else
                if(v[1]> ans.back()[1])
                    ans.back()[1]= v[1];
              
        }
        return ans;
    }
};