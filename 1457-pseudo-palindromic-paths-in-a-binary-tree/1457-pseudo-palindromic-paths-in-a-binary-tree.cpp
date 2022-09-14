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
    void count(vector<int> &map, int &ans){
        int a=0;
        for(int i=0;i<10;i++)
            if(map[i]%2==1)
                a++;
        if(a<=1)
            ans++;
    }
    void solve(Node* node, vector<int> &map, int &ans){
        if(!node)
            return;
        
        map[node->val]++;
        
        if(!node->left && !node->right)
            count(map, ans);
        
        solve(node->left, map, ans);
        solve(node->right, map, ans);
        
        map[node->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        vector<int> map(10,0);
        solve(root, map, ans);
        return ans;
    }
};