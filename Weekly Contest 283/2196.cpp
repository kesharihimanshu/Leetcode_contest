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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int,bool>m;
       unordered_map<int,TreeNode*>mp;
        for(auto &d:des){
            m[d[1]]=true;
            if(m[d[0]]==false)
            m[d[0]]=false;
            if(mp.count(d[0])==0){
            TreeNode* a=new TreeNode(d[0]);
                if(d[2]==1){
                    if(mp.count(d[1])==0){
                        TreeNode* b=new TreeNode(d[1]);
                        a->left=b;
                        mp[d[1]]=b;
                    }
                    else{
                        a->left=mp[d[1]];
                    }
                    
                }
                else{
                    if(mp.count(d[1])==0){
                        TreeNode* b=new TreeNode(d[1]);
                        a->right=b;
                        mp[d[1]]=b;
                    }
                    else{
                        a->right=mp[d[1]];
                    } 
                }
                   
            mp[d[0]]=a;
            }
            else{
                   if(d[2]==1){
                     if(mp.count(d[1])==0){
                        TreeNode* b=new TreeNode(d[1]);
                        mp[d[0]]->left=b;
                        mp[d[1]]=b;
                    }
                    else{
                    mp[d[0]]->left=mp[d[1]];
                    }
                }
                else
                {
                    if(mp.count(d[1])==0){
                        TreeNode* b=new TreeNode(d[1]);
                        mp[d[0]]->right=b;
                        mp[d[1]]=b;
                    }
                    else{
                        mp[d[0]]->right=mp[d[1]];
                    }
                }
                
            }
            
        }
        int ans=-1;
        for(auto &it:m){
            if(it.second==false){
                ans=it.first;
                break;
            }
        }
        return mp[ans];
    }
};