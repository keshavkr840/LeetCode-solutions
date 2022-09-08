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
    bool isSame(Node* a, Node* b){
        
        if(!a || !b){
            if(!a && !b)
                return true;
            return false;
        }
        
        return (a->val== b->val && isSame(a->right, b->left) && isSame(a->left, b->right));
    }
    bool isSymmetric(TreeNode* root) {
        if(root)
            return isSame(root->left, root->right);
        return false;
    }
};