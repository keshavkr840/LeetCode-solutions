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
    Node* solve(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &map, int start, int end, int &i){
        if(start> end) return nullptr;
        
        Node* curr= new Node(preorder[i]);
        int pos= map[preorder[i++]];
        
        curr->left= solve(preorder, inorder, map, start, pos-1, i);
        curr->right= solve(preorder, inorder, map, pos+1, end, i);
        
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        int n= inorder.size();
            
        for(int i=0;i<n;i++)
            map[inorder[i]]=i;
        
        int i=0;
        return solve(preorder, inorder, map, 0, n-1, i);
    }
};