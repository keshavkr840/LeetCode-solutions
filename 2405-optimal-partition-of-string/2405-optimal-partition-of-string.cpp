class Solution {
public:
    int partitionString(string s) {
        vector<int> cnt(26,0);
        
        int ans=0;
        for(auto &c: s){
            
            if(cnt[c-'a']>0){
                ans++;
                
                fill(cnt.begin(), cnt.end(),0);
            }
            cnt[c-'a']++;
                
        }
        return ans+1;
    }
};