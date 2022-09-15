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
    void flatten(TreeNode* root) {
        auto node = root;
        stack<Node*> st;
        
        while(node){
            if(node->right)
                st.push(node->right);
            
            if(node->left){
                node->right= node->left;
                node->left= nullptr;
            }
                
            else{
                if(st.empty()) break;
                node->right= st.top();
                st.pop();
            }
            node= node->right;
        }
    }
};