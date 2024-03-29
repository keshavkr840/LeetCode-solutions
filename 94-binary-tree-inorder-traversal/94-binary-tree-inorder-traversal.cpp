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
#define pb push_back
#define Node TreeNode
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<Node*> st;
        vector<int> ans;
        auto node = root;
        
        while(true){
            if(node){
                st.push(node);
                node= node->left;
            } 
            else{
                if(st.empty()) break;
                node= st.top(); st.pop();
                ans.pb(node->val);
                node= node->right;
            }
            
        }
        return ans;
    }
};