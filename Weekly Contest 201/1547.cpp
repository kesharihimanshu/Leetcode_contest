class Solution {
public:
    int dp[102][102];// dp for memoization
    // startid -> starting index for the current wood piece
    // endid-> same as above
    // s ->length starting
    // e->length ending.
    int solve(vector<int>& c,int startid,int endid,int s,int e)
    {
        if(startid>endid)
            return 0;
        if(dp[startid][endid]!=-1)
            return dp[startid][endid];
        int curr=e-s;
        int ans=INT_MAX;
        for(int i=startid;i<=endid;i++)
        {
          ans=min(ans,curr+solve(c,startid,i-1,s,c[i])+solve(c,i+1,endid,c[i],e));  
        }
        return dp[startid][endid]=ans;
    }
    int minCost(int n, vector<int>& c) {
        sort(c.begin(),c.end());
        memset(dp,-1,sizeof(dp));
        return solve(c,0,c.size()-1,0,n);
        
    }
};

