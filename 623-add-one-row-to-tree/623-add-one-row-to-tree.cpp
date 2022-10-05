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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<Node*> q;
        if(depth==1){
            Node* node= new Node(val);
            node->left= root;
            return node;
        }
            
        int curr=1;
        q.push(root);
        
        while(curr<depth-1){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto node= q.front();
                q.pop();
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            curr++;
        }
        
        int n =q.size();
        for(int i=0;i<n;i++){
            auto node= q.front();
            q.pop();
            
            Node* node1= new Node(val);
            Node* node2= new Node(val);
            
            node1->left= node->left;
            node2->right= node->right;
            
            node->left= node1;
            node->right= node2;
            
        }
        
        return root;
        
    }
};