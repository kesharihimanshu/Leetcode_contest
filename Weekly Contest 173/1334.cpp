bool com (pair<int,int> i,pair<int,int> j)
{
  if(i.first!=j.first)
    return  i.first<j.first;
    return i.second>j.second;
}
class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>m;
    vector<pair<int,int>>ans;
    void solve(int u,int n,int k)
    {
        vector<int>dis(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
        dis[u]=0;
        q.push({0,u});
        while(!q.empty())
        {
            int x=q.top().second;
            int d=q.top().first;
            q.pop();
            for(auto v:m[x])
            {
                if(dis[v.first]>dis[x]+v.second){
                    dis[v.first]=dis[x]+v.second;
                q.push({dis[v.first],v.first});}
                    
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(i!=u && dis[i]<=k)
                cnt++;
        }
     
        ans.push_back({cnt,u});
        
    }
    int findTheCity(int n, vector<vector<int>>& e, int d) {
        for(int i=0;i<e.size();i++)
        {
            m[e[i][0]].push_back({e[i][1],e[i][2]});
             m[e[i][1]].push_back({e[i][0],e[i][2]});
        }
        for(int i=0;i<n;i++)
        {
            solve(i,n,d); 
        }
        sort(ans.begin(),ans.end(),com);
        
        return ans[0].second;
    }
};