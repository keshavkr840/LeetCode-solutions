class Solution {
private:
    bool findPattern(string &word, string &patt){
        unordered_map<char, char> wMap, pMap;
        
        int sz= patt.size();
        
        for(int i=0;i<sz;i++){
            char w= word[i];
            char p= patt[i];
            
            if(wMap.find(w)== wMap.end()) wMap[w]= p;
            if(pMap.find(p)== pMap.end()) pMap[p]=w;
            
            if(wMap[w]!=p || pMap[p]!=w)
                return false;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(auto & word: words)
            if(findPattern(word, pattern))
                ans.push_back(word);
        
        return ans;
    }
};