class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> comp(26,0);
        int m = s.length();
        if(m!= t.length()) return false;
        
        for(int i=0;i<m;i++){
            comp[s[i]-'a']++;
            comp[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++)
            if(comp[i]!=0) return false;
        return true;
    }
};