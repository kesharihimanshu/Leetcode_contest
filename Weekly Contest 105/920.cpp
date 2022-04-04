class Solution {
public:
    int numMusicPlaylists(int m, int n, int k) {
        int mod=1e9+7;
        vector<vector<long long int>>dp(n+1,vector<long long int>(m+1));// 2-D vector for DP
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(j>k)// If taken songs is more than k then we can you that all song again.
                {
                    
                    dp[i][j]=((dp[i-1][j-1]*(m-(j-1)))%mod+dp[i-1][j]*(j-k))%mod;
                    // Taking new song or reuse of used songs.
                }else{
                    dp[i][j]=(dp[i-1][j-1]*(m-(j-1)))%mod;
                    // solution for i-1 songs from j-1 songs multiply by number of left songs.
                }
            }
        }
        return dp[n][m];
    }
};