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
    int check(Node* node){
        if(!node) return 0;
        
        int left = check(node->left);
        if(left!=-1){
            int right= check(node->right);
            if(right!=-1){
                if(abs(left-right)<= 1){
                    return (max(left, right)+1);
                }
            }
            
        }
         
        return -1;
    }
    bool isBalanced(TreeNode* root) {
        auto p= check(root);
        if(check(root)!=-1) return true;
        else return false;
    }
};