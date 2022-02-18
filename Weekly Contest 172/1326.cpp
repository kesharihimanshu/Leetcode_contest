class Solution {
public:
    int minTaps(int n, vector<int>& r) {
        vector<int>dp(n+1,n+2);
        dp[0]=0;
        
        for(int i=0;i<r.size();i++)
        {
            int lb=max(0,i-r[i]+1);
            int ub=min(n,i+r[i]);
          
            for(int j=lb;j<=ub;j++)
            {
               dp[j]=min(dp[j],dp[max(i-r[i],0)]+1);
                
            }
        }
        if(dp[n]==n+2)
            return -1;
        return dp[n];
    }
};
 