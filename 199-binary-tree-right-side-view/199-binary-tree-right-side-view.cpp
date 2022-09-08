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
    void solve(TreeNode* node, int level, vector<int> &ans){
        if(ans.size()==level)
            ans.push_back(node->val);
        
        if(node->right)
            solve(node->right, level+1, ans);
        if(node->left)
            solve(node->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root) solve(root, 0, ans);
        return ans;
    }
};