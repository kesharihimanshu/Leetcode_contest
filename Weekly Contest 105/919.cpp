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
class CBTInserter {
public:
    TreeNode* ans;
    CBTInserter(TreeNode* root) {
        ans=root;
        
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            bool fl=false;
            for(int i=0;i<sz;i++)
            {
                auto u=q.front();
                q.pop();
                par.push(u);
                if(u->left!=NULL)
                {
                    child.push(u->left);
                    q.push(u->left);
                }
                else
                    fl=true;
                 if(u->right!=NULL)
                {
                    child.push(u->right);
                    q.push(u->right);
                }
                else
                    fl=true;
                    
            }
            if(fl==true)
                break;
            if(!q.empty())
            {
                par=child;
                while(!child.empty())
                    child.pop();
               
            }
                
        }
    }
    queue<TreeNode*>par;
    queue<TreeNode*>child;
    int insert(int val) {
        while(!par.empty() && par.front()->left!=NULL && par.front()->right!=NULL)
            par.pop();
        if(par.empty())
        {
            par=child;
           while(!child.empty())
                    child.pop();
        }
        if(par.front()->left==NULL)
        {
            TreeNode* r=new TreeNode(val);
            par.front()->left=r;
            child.push(r);
        }
        else if(par.front()->right==NULL)
        {
          TreeNode* r=new TreeNode(val);
            par.front()->right=r;  
            child.push(r);
        }
        return par.front()->val;
    }
    
    TreeNode* get_root() {
        return ans;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */