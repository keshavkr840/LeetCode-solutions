class TrieNode{
    public:
    bool isLast= false;
    TrieNode *next[26];
    
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
    private:
    TrieNode* root;
    
    public:
    Trie(){
        root= new TrieNode();
    }
    
    TrieNode* getRoot(){
        return root;
    }
    
    void push(vector<string> &words){
        for(auto &word: words){
            insert(word);
        }
        // return root;
    }
    void insert(string &word){
        auto node= root;
        for(int i=0;i<word.size();i++){
            if(!node->containsChar(word[i]))
                node->makeNode(word[i]);
            
            node= node->getNode(word[i]);
        }
        node->isLast= true;
    }
    
};
class Solution {
private:
    void dfs(vector<vector<char>>& board, int &m , int &n, set<string> &ans, TrieNode* node, int i, int j, string res){
        if(i<0 || j<0 || i==m || j==n || board[i][j]=='0' || !node-> containsChar(board[i][j])) return;
        
        node= node->getNode(board[i][j]);
        res+=board[i][j];
        if(node->isLast){
            ans.insert(res);
        }
        
        char c= board[i][j];
        board[i][j]='0';
        
        dfs(board, m, n, ans, node, i,j-1, res);
        dfs(board, m, n, ans, node, i,j+1, res);
        dfs(board, m, n, ans, node, i-1,j, res);
        dfs(board, m, n, ans, node, i+1,j, res);
        
        board[i][j]=c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie= new Trie();
        trie->push(words);
        TrieNode* root= trie->getRoot();
        
        int m = board.size();
        int n = board[0].size();
        set<string> ans;
        
        string res="";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board, m, n, ans, root, i,j, res);
            }
        }
        
        vector<string> v;
        for(auto &s: ans)
            v.push_back(s);
        
        return v;
    }
};