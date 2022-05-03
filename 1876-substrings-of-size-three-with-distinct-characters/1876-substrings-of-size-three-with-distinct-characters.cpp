class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size()-2,ans=0;
        
        for(int i=0;i<n;i++){
            if(s[i]!=s[i+1] && s[i+1]!=s[i+2] && s[i+2]!=s[i]) ++ans;
        }
        return ans;
    }
};