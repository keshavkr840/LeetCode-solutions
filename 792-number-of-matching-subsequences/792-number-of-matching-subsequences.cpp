class Solution {
private:
    bool checkIsSubseq(string& word, vector<int>  pos[], int i, int currpos){
        
        if(i==word.size()) return true;
        int ch = word[i]-'a';
        int newIdx= upper_bound(pos[ch].begin(), pos[ch].end(), currpos) -pos[ch].begin();
        if(newIdx==pos[ch].size()) return false;
        else return checkIsSubseq(word, pos, i+1, pos[ch][newIdx]);
        
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> pos[26];
        
        for(int i=0;i<s.size();i++){
            pos[s[i]-'a'].push_back(i);
        }
        
        int ans=0;
        for(auto&word: words){
            if(checkIsSubseq(word, pos, 0,-1)) ++ans;
        }
        return ans;
    }
};