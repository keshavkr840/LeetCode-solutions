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
    int heightRight(Node* node){
        int cnt=0;
        while(node){
            node=node->right;
            cnt++;
        }
        return cnt;
    }
    int heightLeft(Node* node){
        int cnt=0;
        
        while(node){
            node=node->left;
            cnt++;
        }
        return cnt;
    }
    int countNodes(TreeNode* node) {
        if(!node)
            return 0;
        
        int left= heightLeft(node);
        int right= heightRight(node);
        if(left== right)
            return pow(2,left)-1;
        else
            return 1+ countNodes(node->left)+ countNodes(node->right);
    }
};