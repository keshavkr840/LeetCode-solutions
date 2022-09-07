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
#define pb push_back
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        bool flag =0;
        
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            Node* curr;
            
            for(int i=0;i<n;i++){
                curr= q.front();
                q.pop();
                
                temp.pb(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            if(flag)
                reverse(temp.begin(), temp.end());
            flag^=1;
            ans.pb(temp);
        }
        
        return ans;
    }
};