class Solution {
public:
    int minimumWhiteTiles(string floor, int cnt, int cl) {
        int n=floor.size();
        if(cnt*cl>=n)
            return 0;
      
        vector<vector<int>>dp(n+1,vector<int>(cnt+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=cnt;j++)
            {
              int op1=dp[i-1][j]+floor[i-1]-'0';
                int op2=j>0?dp[max(0,i-cl)][j-1]:1000;
                dp[i][j]=min(op1,op2);
            }
        }
        return dp[n][cnt];
        
        
        
    }
};