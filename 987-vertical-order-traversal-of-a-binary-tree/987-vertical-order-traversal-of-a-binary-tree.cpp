/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define Node TreeNode
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> map;
        
        queue<pair<int, Node*>> q;
        q.push({0,root});
        
        while(!q.empty()){
            
            int n = q.size();
            multiset<pair<int, int>> temp;
            
            for(int i=0;i<n;i++){
                auto [col, node]= q.front();
                q.pop();
                
                temp.insert({col, node->val});
                if(node->left) q.push({col-1, node->left});
                if(node->right) q.push({col+1, node->right});
            }
            
            for(auto &p:temp)
                map[p.first].push_back(p.second);
            
        }
        vector<vector<int>> ans;
        for(auto &it :map)
            ans.push_back(it.second);
        return ans;
    }
};