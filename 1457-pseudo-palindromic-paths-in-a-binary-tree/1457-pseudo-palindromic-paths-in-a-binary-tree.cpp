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
private:
    int ans=0;
    void solve(Node * node, int path){
        if(!node)
            return;
        
        path^= (1<<node->val);
        
        if(!node->left && !node->right)
            if((path &(path-1))==0)
                ans++;
        
        solve(node->left, path);
        solve(node->right, path);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};