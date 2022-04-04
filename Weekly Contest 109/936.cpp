class Solution {
public:
    void update(string &a,int id,int sz)
    {
        for(int i=id;i<id+sz;i++)
            a[i]='*';
        return;
        
    }
    int solve(string stamp,string target)
    {
       
        for(int i=0;i<=target.size()-stamp.size();i++)
        {
            int j=i;
            int u=0;
             bool fl=false;
            while(j<target.size()&& u<stamp.size() && (stamp[u]==target[j]||target[j]=='*'))
            {
                if(target[j]!='*')
                    fl=true;
                j++;
                u++;
            }
            if(fl && u==stamp.size())
                return i;
        }
        return -1;
    }
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>ans;
        int n=target.size();
        string a;
        for(int i=0;i<n;i++)
        {
            a.push_back('*');
        }
        while(a!=target)
        {
            int u=solve(stamp,target);
            if(u>=0)
            {
                update(target,u,stamp.size());
                ans.push_back(u);
            }
            else{
                if(a==target)
                    break;
                return {};
            }
        }
        if(ans.size()>10*n)
            return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};