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
    int mx=INT_MIN;
    int maxSum(Node* node){
        if(!node) return 0;
        
        int left= max(maxSum(node->left),0);
        int right= max(maxSum(node->right),0);
        
        mx= max(mx, node->val+ left+ right);
        return node->val+ max(left, right);
    }
public:
    
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return mx;
    }
};