class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       int u=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
               
                dp[i][j]=max(dp[i-1][j-1]+a[i-1]*b[j-1],max(dp[i-1][j],dp[i][j-1]));
                u=max(u,a[i-1]*b[j-1]);
                
            }
        }
        if(dp[n][m]==0)
            return u;
    return dp[n][m];
    }
};