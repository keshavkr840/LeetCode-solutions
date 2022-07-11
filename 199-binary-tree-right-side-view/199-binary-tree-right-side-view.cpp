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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; 
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        int value;
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* curr= q.front();
                value= curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
                q.pop();
            }
            ans.push_back(value);
        }
        return ans;
    }
};