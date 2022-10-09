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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> map;
        queue<Node*> q;
        q.push(root);
        Node* node;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                node= q.front();
                q.pop();
                
                if(map.find(k-node->val)!= map.end())
                    return true;
                
                map.insert(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return false;
    }
};