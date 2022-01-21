class Solution {
public:
   int inf=INT_MAX;
    int minCost(int t, vector<vector<int>>& edges, vector<int>& fee) {
        int n=fee.size();
       vector<vector<int>>dp(t+1,vector<int>(n,inf));//we make a dp array.
       
       vector<pair<int,int>>m[n];//adjecency matrix
        for(auto &e:edges)
        {
            m[e[0]].push_back({e[1],e[2]});
             m[e[1]].push_back({e[0],e[2]});
            
        }
        dp[0][0]=fee[0];
        for(int i=0;i<=t;i++)
        {
            for(int u=0;u<n;u++)
            {
                if(dp[i][u]!=inf)// if we reach at u in time i;
                {
                    for(auto &v:m[u])
                    {
                        int node=v.first;
                        int tm=v.second;
                        if(i+tm<=t)
                        {
                           dp[i+tm][node]=min(dp[i][u]+fee[node],dp[i+tm][node]) ;//updating the dp.
                        }
                    }
                }
            }
        }
        int ans=inf;
        for(int i=0;i<=t;i++)
        {
            ans=min(ans,dp[i][n-1]);// ans is in dp[time][n-1].
        }
        return ((ans==inf)?-1:ans);
        
    }
};