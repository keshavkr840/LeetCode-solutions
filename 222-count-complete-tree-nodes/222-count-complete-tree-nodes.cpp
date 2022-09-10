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
class Solution {
public:
    int countNodes(TreeNode* node) {
        if(!node) return 0;
        
        int left= heightLeft(node->left);
        int right = heightRight(node->right);
        
        if(left==right)
            return (1<<left)-1;
        else
            return 1+ countNodes(node->left)+ countNodes(node->right);
    }
    int heightLeft(TreeNode* node){
        int height=1;
        while(node){
            node= node->left;
            height++;
        }
        return height;
    }
    int heightRight(TreeNode* node){
        int height=1;
        while(node){
            node= node->right;
            height++;
        }
        return height;
    }
};