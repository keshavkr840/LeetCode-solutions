class TrieNode{
    public:
    TrieNode* next[2];
    
    bool contains(int bit){
        return next[bit]!= nullptr;
    }
    void makeNode(int bit){
        next[bit]= new TrieNode();
    }
    TrieNode* getNode(int bit){
        return next[bit];
    }
};
class Trie{
    TrieNode * root;
    public:
    
    Trie(){
        root = new TrieNode();
    }
    
    void insert(int & num){
        auto node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->contains(bit)) node->makeNode(bit);
            node = node->getNode(bit);
        }
    }
    
    int getMax(int & num){
        auto node =root;
        
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) &1;
            if(node->contains(1-bit)){
                maxNum |= (1<<i);
                node= node->getNode(1-bit);
            }
            else{
                node=node->getNode(bit);
            }              
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        
        for(auto &num: nums){
            trie.insert(num);
        }
        
        int mx=0, temp=0;
        for(auto &num: nums){
            temp= trie.getMax(num);
            mx= max(mx,temp);
        }
        return mx;
    }
};