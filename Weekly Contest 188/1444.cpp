class Solution {
public:
    long long dp[51][51][11];//dp for memoization
    int mod=1e9+7;
    int n,m;
    int solve(int x,int y,int k,vector<string>& pizza,int left)
    {
        if(dp[x][y][k]!=-1)
            return dp[x][y][k];
        long long ans=0;
        if(k==1)
        {
            if(left>0)
                return 1;
            return 0;
        }
        int row=0;
        for(int i=n-1;i>x;i--)// For horizontal cut
        {
            for(int j=y;j<m;j++)
            {
                row+=(pizza[i][j]=='A');
            }
            if(row>0 && left-row>0)
            {
                ans+=solve(i,y,k-1,pizza,row);
                ans=ans%mod;
            }
        }

        int col=0;
        for(int j=m-1;j>y;j--)
        {
            for(int i=x;i<n;i++)
            {
                col+=(pizza[i][j]=='A');
            }
            if(col>0 && left-col>0)
            {
                ans+=solve(x,j,k-1,pizza,col);
                ans=ans%mod;
            }
        }

        dp[x][y][k]=ans;
        return ans;
        
    }
    
    int ways(vector<string>& pizza, int k) {
        memset(dp,-1,sizeof(dp));
        n=pizza.size();
        m=pizza[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cnt+=(pizza[i][j]=='A');
            }
        }
        return solve(0,0,k,pizza,cnt);
    }
};