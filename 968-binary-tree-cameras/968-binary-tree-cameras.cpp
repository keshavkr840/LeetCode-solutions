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
    enum camera{hasCam, needsCam, hasCover};
    int cam=0;
    
    camera solve(Node* root){
        if(root== nullptr) return hasCover;
        
        camera l = solve(root->left);
        camera r = solve(root->right);
        
        if(l==needsCam || r==needsCam){
            ++cam;
            return hasCam;
        }
        
        if(l==hasCam || r== hasCam){
            return hasCover;
        }
        
        //both the childs haveCover(majorly for the leaf node case)
        return needsCam; 
    }
    int minCameraCover(TreeNode* root) {
        return ( solve(root)== needsCam)? ++cam: cam;
    }
};