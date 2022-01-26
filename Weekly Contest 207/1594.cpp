class Solution {
public:
    #define ll long long
    ll mod=1000000007;
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pair<ll,ll>>>dp(n,vector<pair<ll,ll>>(m));
        dp[0][0]={grid[0][0],grid[0][0]};
        for(int i=1;i<n;i++)
        {
           
            dp[i][0].first=grid[i][0]*dp[i-1][0].first;
            dp[i][0].second=grid[i][0]*dp[i-1][0].first;
            // dp[i][0].first=dp[i][0].first %mod;
            //  dp[i][0].second=dp[i][0].second %mod;
        }
        for(int i=1;i<m;i++)
        {
              dp[0][i]={grid[0][i]*dp[0][i-1].first,grid[0][i]*dp[0][i-1].first};
            // dp[0][i].first=dp[0][i].first %mod;
            //  dp[0][i].second=dp[0][i].second %mod; 
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                
                    int a=grid[i][j];
                    ll a1=max(dp[i-1][j].first * a,dp[i][j-1].first * a);
                    ll a2=max(dp[i-1][j].second * a,dp[i][j-1].second * a);
                    dp[i][j].first=max(a1,a2);
                     a1=min(dp[i-1][j].first * a,dp[i][j-1].first * a);
                     a2=min(dp[i-1][j].second * a,dp[i][j-1].second * a);
                    dp[i][j].second=min(a1,a2);
             //         dp[i][j].first=dp[i][j].first %mod;
             // dp[i][j].second=dp[i][j].second %mod;
                }
               
            }
        
        if(dp[n-1][m-1].first<0)
            return -1;
        return dp[n-1][m-1].first%mod;
    }
};