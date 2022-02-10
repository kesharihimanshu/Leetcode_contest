class Solution {
public:
   unordered_map<int,vector<int>>m;
    int ans=0;
    bool dfs(int u,int p,vector<bool>& h)
    { bool fl=false;
        for(auto &v:m[u])
        {
            if(v==p)
                continue;
           bool r=dfs(v,u,h);
            if(r==true){
                fl=true;
                ans+=2;}
        }
     return (fl||h[u]);
        
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& h) {
        for(auto &e:edges)
        {
            m[e[0]].push_back(e[1]);
             m[e[1]].push_back(e[0]);
            
        }
        bool y=dfs(0,-1,h);
        return ans;
        
    }
};