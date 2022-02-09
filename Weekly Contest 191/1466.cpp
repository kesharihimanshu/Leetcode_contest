class Solution {
public:
    vector<bool>vis;
    map<int,vector<int>>m;
    int ans=0;
 
    int minReorder(int n, vector<vector<int>>& con) {
        vis.resize(n,false);
        for(auto &v:con)
        {
            m[v[0]].push_back(v[1]);
            m[v[1]].push_back(-v[0]);  
        }
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            auto u=q.front();
            q.pop();
            if(vis[u])
                continue;
            vis[abs(u)]=true;
            for(auto &v:m[u])
            {
                if(vis[abs(v)]==false)
                {
                    q.push(abs(v));
                    if(v>0)
                        ans++;
                }
            }
        }
        return ans;
    
    }
};