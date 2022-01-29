class Solution {
public:
    int p[502];// for prefix sum;
    int dp[502][502];// for memoization
    int solve(int start,int end)// recursive calls
    {
        if(start>=end)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        int ans=0;
        for(int i=start;i<end;i++)
        {
           int left=p[i]-p[start-1];
            int right=p[end]-p[i];
            if(left<right)
            {
                ans=max(ans,left+solve(start,i));
                
            }
            else if(left>right)
            {
                ans=max(ans,right+solve(i+1,end));
            }
            else
            {
                ans=max(ans,max(left+solve(start,i),right+solve(i+1,end)));
            }
        }
        return dp[start][end]=ans;
    }
    int stoneGameV(vector<int>& s) {
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=s.size();i++)
        {
            p[i]=p[i-1]+s[i-1];
        }
        return solve(1,s.size());
    }
};