class Solution {
public:
    unordered_map<int,vector<int>>m;
    vector<int>ans;
    bool fl=false;
    void solve(int target,int node,vector<int>&b,vector<bool>&vis)
    {
        if(vis[node]||fl)
            return ;
        vis[node]=true;
        for(auto &v:m[node])
        {
            b.push_back(node);
            if(v==target)
            {
                cout<<node<<" ";
                ans=b;
                fl=true;
                return;
            }
            solve(target,v,b,vis);
            b.pop_back();
            
        }
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        for(auto &e:edges)
        {
            m[e[0]].push_back(e[1]);
             m[e[1]].push_back(e[0]); 
        }
        if(target==1)
        {
            if(t==0)
                return 1.0;
            if(m[1].size()==0)
                return 1.0;
            return 0;
        }
        ans.clear();
        vector<bool>vis(n+1,false);
        vector<int>b;
        solve(target,1,b,vis);
        if(ans.size()>t)
            return 0;
        if(t>ans.size())
        {
            if(m[target].size()>1)
                return 0;
        }
        double sum=1.0;
        cout<<ans.size()<<" ";
        for(auto &c:ans)
        {
            // cout<<c<<" "<<m[c].size();
            double h=m[c].size();
            if(c!=1)
                 h=h-1;
            sum*=(double)(1.0/h);
        }
        return sum;
    }
};