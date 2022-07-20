class TrieNode{
    public:
    TrieNode* next[26];
    int isLast = 0;
    
    bool containsChar(char ch){
        return next[ch-'a']!= nullptr;
    }
    void makeNode(char ch){
        next[ch-'a']= new TrieNode();
    }
    TrieNode* getNode(char ch){
        return next[ch-'a'];
    }
    
};

class Trie{
    
    // void clear(TrieNode* root){
    //     for(int i=0;i<26;i++){
    //         if(root->next[i]) clear(root->next[i]);
    //     }
    //     delete root;
    // }
    
    public:
    
    TrieNode * root;
    
    Trie(){
        root = new TrieNode();
    }
    
    // ~Trie(){
    //     clear(root);
    // }
    
    void insert(string &word){
        auto node = root;
        
        for(int i=0;i<word.size();i++){
            if(!node->containsChar(word[i])) node->makeNode(word[i]);
            node= node->getNode(word[i]);
        }
        node->isLast++;
    }
    
    int dfs(TrieNode* root, string &s, vector<int> pos[], int idx){
        int res=0;
        
        for(int i=0;i<26;i++){
            if(root->next[i]){
                
                int nextIdx= upper_bound(pos[i].begin(), pos[i].end(), idx)- pos[i].begin();
                if(nextIdx==pos[i].size()) continue;
                res+= dfs(root->next[i], s,pos, pos[i][nextIdx]);
            }
        }
        return res+ root->isLast;
    }
};
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        Trie trie;
        
        for(auto &word: words){
            trie.insert(word);
        }
        
        vector<int> pos[26];
        
        
        for(int i=0;i<s.size();i++){
            pos[s[i]-'a'].push_back(i);
        }
        
        return trie.dfs(trie.root, s, pos,-1);
        
    }
};