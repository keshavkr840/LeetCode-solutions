class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        for(auto c: s)
            v[c-'a']++;
        
        int ans=0;
        unordered_map<int,bool> map;
        
        for(auto n: v){
            if(n==0) continue;
            if(map.find(n)==map.end())
                map[n]= true;
            else
            {
                while(map.find(n)!=map.end()){
                    ++ans;
                    --n;
                    // if(n==0) break;
                }
                if(n!=0) map[n]= true;
            }
        }
        return ans;
    }
};