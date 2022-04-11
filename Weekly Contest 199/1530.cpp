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
   vector<int> dfs(TreeNode* root,int dis)
    {
        vector<int>v;
       if(!root)
           return v;
       vector<int>left=dfs(root->left,dis);
       vector<int>right=dfs(root->right,dis);
       for(auto &i:left)
       {
          i++; 
           v.push_back(i);
       }
         for(auto &i:right)
       {
          i++; 
             v.push_back(i);
       }
       for(auto &i:left)
       {
           for(auto &j:right)
           {
               if(i+j<=dis)
                   ans++;
           }
       }
       if(root->left==NULL && root->right==NULL)
       {
           v.push_back(0);
       }
       return v;
       
    }
    int countPairs(TreeNode* root, int dis) {
       vector<int>a= dfs(root,dis);
        return ans;
    }
};