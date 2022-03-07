class Solution {
public:
    int k;
    unordered_map<int,vector<int>>m;
    void dfs(int u,int y,vector<bool>&vis,vector<vector<int>>&ans){
        if(vis[u])
            return;
        vis[u]=true;
        for(auto &v:m[u])
        {
            if(vis[v]==false){
                ans[v].push_back(y);
                dfs(v,y,vis,ans);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        for(auto it:edges){
            m[it[0]].push_back(it[1]);
        }
         vector<vector<int>>ans(n);
           vector<bool>vis(n,false);
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++)
               vis[j]=false;
           dfs(i,i,vis,ans);}
        return ans;
    }
};