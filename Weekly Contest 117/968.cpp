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
    int need=0;
    int has_camera=1;
    int cover=2;
    int Not_needed=3;
    int solve(TreeNode* root)
    {
        if(!root)
            return Not_needed;
        //leaf
        if(root->left==NULL && root->right==NULL)
        {
            return need;
        }
        int lefts=solve(root->left);
        int rights=solve(root->right);
        
        if(lefts==need || rights==need)
        {
            ans++;
            return has_camera;
        }
        if(lefts==has_camera || rights==has_camera)
        {
            return cover;
        }
        return need;
    }
    int minCameraCover(TreeNode* root) {
        ans=solve(root)==need?ans+1:ans;
        return ans;
    }
};