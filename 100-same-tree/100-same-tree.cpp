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
    bool isSame(Node * a, Node* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        
        return (a->val == b->val  && isSame(a->left, b->left) && isSame(a->right,b->right));
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p,q);
    }
};