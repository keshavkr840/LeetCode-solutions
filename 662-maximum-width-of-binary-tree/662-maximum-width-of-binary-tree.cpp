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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<Node*, long long>> q;
        q.push({root,0});
        long long ans=0;
        
        while(!q.empty()){
            ans= max(ans, q.back().second- q.front().second+1);
            int first= q.front().second;
            
            int n = q.size();
            while(n--){
                auto [node, num]= q.front(); q.pop();
                
                if(node->left) q.push({node->left, 2*(num- first)+1});
                if(node->right) q.push({node->right, 2*(num- first)+2});
            }
        }
        return ans;
    }
};