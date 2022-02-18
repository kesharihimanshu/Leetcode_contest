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
    vector<int>v;
    void solve(TreeNode* root)
    {
        if(!root)
            return;
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
        return;
    }
    TreeNode* buildTree(int start,int end)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode *a= new TreeNode(v[mid]);
        a->left=buildTree(start,mid-1);
        a->right=buildTree(mid+1,end);
        return a;
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        solve(root);
        return buildTree(0,v.size()-1);
        
    }
};