class Solution {
public:
    int minGroups(vector<vector<int>>& val) {
        multiset<int> set;
        int n = val.size();
        sort(val.begin(), val.end());
        set.insert(val[0][1]);
        
        
        for(int i=1;i<n;i++){
            auto it= set.lower_bound(val[i][0]);
            
            if(it== set.end()){
                set.erase(set.begin());
            }
            
            else if(it!= set.begin()){
                set.erase(--it);
            }
            
            set.insert(val[i][1]);
        }
        return set.size();
    }
};