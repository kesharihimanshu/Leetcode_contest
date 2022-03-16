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
    void solve(TreeNode *root,int s,int l)
    {
        if(!root)
            return;
       if(s!=-1)
       {
           ans=max(ans,max(abs(root->val-s),abs(root->val-l)));
           s=min(s,root->val);
           l=max(l,root->val);
       }
        else
        {
            s=root->val;
            l=root->val;
        }
       
        solve(root->left,s,l);
        solve(root->right,s,l);
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        int s=-1,l=-1;
        solve(root,s,l);
        return ans;
    }
};