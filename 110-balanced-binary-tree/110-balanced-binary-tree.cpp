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
    pair<int, bool> check(Node* node){
        if(!node) return (make_pair(0, true));
        auto [left, leftBal] = check(node->left);
        auto [right, rightBal] = check(node->right);
        int res= abs(left-right);
        if(res<=1 && leftBal && rightBal)
            return make_pair(1+max(left, right), true);
        else
            return make_pair(1+max(left, right), false);
    }
    bool isBalanced(TreeNode* root) {
        auto p= check(root);
        if(p.second) return true;
        else return false;
    }
};