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
    int dia=0;
    int depth(Node* node){
        if(!node) return 0;
        
        int left= depth(node->left);
        int right= depth(node->right);
        
        dia= max(dia, left+right);
        return 1+ max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return dia;
    }
};