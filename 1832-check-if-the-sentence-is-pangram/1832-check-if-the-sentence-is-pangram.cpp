class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> check(26, false);
        
        for(auto &c: sentence)
            check[c-'a']= true;
        
        for(int i=0;i<26;i++)
            if(!check[i])
                return false;
        
        return true;
    }
};