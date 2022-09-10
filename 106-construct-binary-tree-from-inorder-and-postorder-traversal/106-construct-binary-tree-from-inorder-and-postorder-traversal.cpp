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
    Node* solve(vector<int> postorder, unordered_map<int, int> &map, int start, int end, int &i){
        if(start>end) return nullptr;
        
        Node* curr= new Node(postorder[i]);
        int pos= map[postorder[i--]];
        
        
        curr->right= solve(postorder, map, pos+1, end, i);
        curr->left= solve(postorder, map, start, pos-1, i);
        
        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        int n = inorder.size();
        for(int i=0;i<n;i++)
            map[inorder[i]]=i;
        
        int i= n-1;
        return solve(postorder, map, 0, n-1, i);
    }
};