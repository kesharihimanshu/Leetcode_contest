class Solution {
public:
    int dp[2001][1001];
    int solve(vector<vector<int>>& piles, int k,int pn)
    {
        if(k==0)
            return 0;
        if(pn>=piles.size())
            return 0;
      
        if(dp[k][pn]!=-1)
            return dp[k][pn];
        int ans=INT_MIN;
        int op1=solve(piles,k,pn+1);
        int sum=0,op2=0;
        for(int i=0;i<piles[pn].size();i++)
        {
            sum+=piles[pn][i];
            if(k-(i+1)>=0)
            {
                op2=max(op2,sum+solve(piles,k-(i+1),pn+1));
            }
        }
       
        ans=max(op1,op2);
        return dp[k][pn]=ans;
        
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(piles,k,0);
    }
};