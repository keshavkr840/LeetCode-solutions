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
    TrieNode* root;
    public:
    Trie(){
        root= new TrieNode();
    }
    
    void insert(int &num){
        auto node = root;
        
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            
            if(!node->contains(bit)) node->makeNode(bit);
            node= node->getNode(bit);
        }
    }
    
    int maxXor(int &num){
        auto node = root;
        int maxNum=0;
        
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->contains(1-bit)){
                maxNum |= (1<<i);
                node = node->getNode(1-bit);
            }
            else{
                node = node->getNode(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        
        int n = nums.size();
        vector<pair<pair<int, int>, int>> q;
        
        for(int i = 0; i < queries.size(); i++) {
            q.push_back({{queries[i][0], queries[i][1]}, i});
        }
        
        sort(nums.begin(), nums.end());
        
        sort(q.begin(), q.end(), [](pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b){
            return a.first.second< b.first.second;
        });
        
        vector<int> ans(queries.size());
        
        int j=0;
        bool flag = false;
        for(auto &query: q){
            
            while(j<n && nums[j]<= query.first.second){
                trie.insert(nums[j]);
                j++;
            }
            
            if(j==0) ans[query.second]= -1;
            else{
                int temp = trie.maxXor(query.first.first);
                ans[query.second]= temp;
            }
        }
        return ans;
            
    }
};