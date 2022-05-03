class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char, int> map;
        int k=3,ans=0;
        int n = s.size()-k+1;
        for(int i=0;i<s.size();++i){
            map[s[i]]++;
            if(i>=k){
                if(map[s[i-k]]==1) map.erase(s[i-k]);
                else map[s[i-k]]--;
            }
            if(map.size()==k) ans++;
            //cout<<map.size()<<endl;
        }
        return ans;
    }
};