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
class Solution {
public:
    bool k=true;
    int a;
    void solve(TreeNode *root)
    {
        if(!root || k==false)
            return;
        if(root->val!=a)
        {
            k=false;
                return;
        }
        solve(root->left);
        solve(root->right);
        return;
            
    }
    bool isUnivalTree(TreeNode* root) {
        a=root->val;
        solve(root);
        return k;
    }
};