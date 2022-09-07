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
        
        int left= max(getSum(node->left),0);
        int right= max(getSum(node->right),0);
        
        mx = max(mx, node->val + left+ right);
            
        return node->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        getSum(root);
        return mx;
    }
};