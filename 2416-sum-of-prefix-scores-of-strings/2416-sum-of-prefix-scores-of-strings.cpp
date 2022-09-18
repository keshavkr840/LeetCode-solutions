class TrieNode{
private:
    char data;
    TrieNode* child[26];
    int freq=0;
public:
    
    void makeNode(char ch){
        child[ch-'a']= new TrieNode();
    }
    bool containsChar(char ch){
        return child[ch-'a']!= nullptr;
    }
    
    TrieNode* getNode(char ch){
        return child[ch-'a'];
    }
    void incFreq(){
        freq++;
    }
    int getFreq(){
        return freq;
    }
    
};
class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string &s){
        auto node= root;
        for(int i=0;i<s.size();i++){
            if(!node->containsChar(s[i]))
                node->makeNode(s[i]);
            node= node->getNode(s[i]);
            node->incFreq();
        }
    }
    int traverse(string &s){
        int cnt=0;
        auto node= root;
        for(int i=0;i<s.size();i++){
            if(!node->containsChar(s[i]))
                break;
            
            node= node->getNode(s[i]);
            if(node->getFreq()==1){
                cnt+=s.size()-i;
                break;
            }
            
            cnt+=node->getFreq();
        }
        return cnt;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(auto &word: words){
            trie.insert(word);
        }
        
        vector<int> ans;
        for(auto &word: words){
            ans.push_back(trie.traverse(word));
        }
        return ans;
    }
};