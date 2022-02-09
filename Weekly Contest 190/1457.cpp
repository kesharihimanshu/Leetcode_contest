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
    int ans=0;
    void dfs(TreeNode* root,int bit)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            bit^=(1<<root->val);
            if(__builtin_popcount(bit)<=1)
            {
                ans++;
            }
            return ;
        }
        dfs(root->left,bit^(1<<root->val));
         dfs(root->right,bit^(1<<root->val));
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};
