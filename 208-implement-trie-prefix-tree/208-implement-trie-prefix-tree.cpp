class TrieNode{
public:
    TrieNode* next[26];
    bool isLast = false;
    
    bool containsChar(char ch){
        if(next[ch-'a']!= nullptr) return true;
        return false;
    }
    
    TrieNode* getNode(char ch){
        return next[ch-'a'];
    }
    
    void makeNode(TrieNode* node, char ch){
        next[ch-'a']= node;
    }
    
    void setLast(){
        isLast = true;
    }
};
class Trie {
private:
    TrieNode * root;
    
    void clear (TrieNode* root){
        for(int i=0;i<26;i++){
            if(root->getNode(i+'a')!=nullptr) clear(root->getNode(i+'a'));
        }
        delete root;
    }
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie(){
        clear(root);
    }
    
    void insert(string word) {
        auto node = root;
        
        for(int i=0;i< word.size();i++){
            if(node->containsChar(word[i])) node = node->getNode(word[i]);
            else {
                node->makeNode(new TrieNode(), word[i]);
                node= node->getNode(word[i]);
            }
        }
        node->setLast();
    }
    
    bool search(string word) {
        auto node =root;
        
        for(int i=0;i<word.length();i++){
            if(node->containsChar(word[i])) node = node->getNode(word[i]);
            else return false;
        }
        return node->isLast;
    }
    
    bool startsWith(string prefix) {
        auto node =root;
        
        for(int i=0;i<prefix.length();i++){
            if(node->containsChar(prefix[i])) node = node->getNode(prefix[i]);
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */