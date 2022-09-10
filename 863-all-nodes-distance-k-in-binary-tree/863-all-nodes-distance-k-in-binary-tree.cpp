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
        q.push(root);
        
        Node* start;
        while(!q.empty()){
            auto node= q.front(); q.pop();
            if(node->val==target->val)
                start= node;
            
            if(node->left){
                parent[node->left]= node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]= node;
                q.push(node->right);
            }
        }
        unordered_set<int> vis;
        q.push(start);
        int level=0;
        
        
        while(!q.empty()){
            int n =q.size();
            if(level==k) break;
            
            for(int i=0;i<n;i++){
                auto node = q.front(); q.pop();
                vis.insert(node->val);
                
                if(node->left && vis.find(node->left->val)== vis.end())
                    q.push(node->left);
                if(node->right && vis.find(node->right->val) ==vis.end())
                    q.push(node->right);
                
                if(parent.find(node)== parent.end()) continue;
                if(vis.find(parent[node]->val)==vis.end())
                    q.push(parent[node]);
            }
            level++;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};