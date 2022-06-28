class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        for(auto c: s)
            v[c-'a']++;
        
        int ans=0;
        unordered_map<int,bool> map;
        
        for(auto n: v){
            while(n && map.find(n)!= map.end()){
                ++ans;
                --n;
            }
            map[n]= true;
        }
        return ans;
    }
};