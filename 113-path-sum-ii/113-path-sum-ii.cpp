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
private:
    vector<vector<int>> ans;
    void solve(Node* node, int req, vector<int> &path){
        if(!node) return;
        
        req-= node->val;
        path.push_back(node->val);
        
        if(!node->left && !node->right && req==0){
            ans.push_back(path);
        }

        solve(node->left, req, path);
        solve(node->right, req, path);
        
        path.pop_back();
        req+= node->val;
          
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root, targetSum, path);
        return ans;
    }
};