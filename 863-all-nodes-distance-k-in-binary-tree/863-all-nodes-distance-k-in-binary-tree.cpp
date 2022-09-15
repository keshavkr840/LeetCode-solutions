/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define Node TreeNode
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<Node*, Node*> parent;
        queue<Node*> q;
        parent[root]= nullptr;
        q.push(root);
        Node* start;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node==target)
                start= target;
            
            if(node->left){
                q.push(node->left);
                parent[node->left]= node;
            }
            if(node->right){
                parent[node->right]= node;
                q.push(node->right);
            }
        }
        
        vector<int> ans;
        unordered_set<int> vis;
        queue<pair<Node*, int>> qu;
        qu.push({start,0});
        
        while(!qu.empty()){
            auto [node, dis]= qu.front();
            qu.pop();
            // if(vis.find(node->val)!= vis.end())
            //     continue;
            vis.insert(node->val);
            
            if(dis==k){
                ans.push_back(node->val);
                continue;
            }
                
            
            if(node->left && vis.find(node->left->val)==vis.end()){
                qu.push({node->left,dis+1});
            }
            if(node->right && vis.find(node->right->val)==vis.end()){
                qu.push({node->right, dis+1});
            }
            if(parent[node] && vis.find(parent[node]->val)==vis.end()){
                qu.push({parent[node], dis+1});
            }
        }
        
        return ans;
    }
};