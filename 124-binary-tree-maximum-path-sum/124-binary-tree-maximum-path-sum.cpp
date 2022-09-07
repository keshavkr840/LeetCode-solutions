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
    int mx=INT_MIN;
    int getSum(Node* node){
        if(!node) return 0;
        
        int left= getSum(node->left);
        int right= getSum(node->right);
        
        mx = max({mx, node->val, node->val+left, node->val + right, node->val + left+ right});
            
        return node->val + max((left>0 ? left :0), (right>0? right:0));
    }
    
    int maxPathSum(TreeNode* root) {
        getSum(root);
        return mx;
    }
};