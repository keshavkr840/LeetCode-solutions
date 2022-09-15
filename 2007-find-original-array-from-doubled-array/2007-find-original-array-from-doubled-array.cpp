class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2!=0) return {};
        
        sort(changed.begin(), changed.end());
        
        unordered_multiset<int>map;
        vector<int> ans;
        
        for(auto &e: changed){
            if(e%2==0){
                auto it = map.find(e/2);
                if(it!=map.end()){
                    map.erase(it);
                    ans.push_back(e/2);
                    continue;
                }
            }
            map.insert(e);
        }
        
        if(map.size()) return {};
        else return ans;
    }
};