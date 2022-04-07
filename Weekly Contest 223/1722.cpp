class Solution {
public:
    unordered_map<int,bool>vis;
     unordered_map<int,vector<int>>g;
    unordered_map<int,int>cnt;
    void dfs(int i,vector<int>& s, vector<int>& target)
    {
        vis[i]=true;
        cnt[s[i]]++;
        cnt[target[i]]--;
        for(auto v:g[i])
        {
            if(vis[v]==false)
                dfs(v,s,target);
        }
    }
    int minimumHammingDistance(vector<int>& s, vector<int>& target, vector<vector<int>>& allowed) {
       
        for(auto &u:allowed){
            g[u[0]].push_back(u[1]);
            g[u[1]].push_back(u[0]);
        }
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(vis[i]==false)
            {
                dfs(i,s,target);
                for(auto it:cnt)
                {
                    if(it.second>0)
                        ans+=it.second;
                }
                cnt.clear();
            }
        }
        return ans;
    }
};