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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<Node*> st;
        stack<int> rev;
        st.push(root);
        
        while(true){
            if(st.empty()) break;
            auto node = st.top();
            st.pop();
            
            rev.push(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        
        vector<int> ans;
        while(rev.size()){
            ans.pb(rev.top());
            rev.pop();
        }
        return ans;
    }
};