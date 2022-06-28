class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        
        for(auto n: s)
            freq[n-'a']++;
        
        sort(freq.begin(), freq.end(), greater<int>());
        
        int maxAllow= s.size(),ans=0;
        
        for(auto &n:freq){
            if(n> maxAllow){
                ans+= n - maxAllow;
                n=maxAllow;
            }
            maxAllow= max(0,n-1);
        }
        return ans;
    }
};