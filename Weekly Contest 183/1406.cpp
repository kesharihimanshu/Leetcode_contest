class Solution {
public:
    int dp[50002];
    int solve(vector<int>& s,int id)
    {
        if(id>=s.size())
            return 0;
        if(dp[id]!=-1)
            return dp[id];
        int ans=INT_MIN;
        ans=max(ans,s[id]-solve(s,id+1));
        if(id+1<s.size())
             ans=max(ans,s[id]+s[id+1]-solve(s,id+2));
          if(id+1<s.size())
             ans=max(ans,s[id]+s[id+1]-solve(s,id+2));
          if(id+2<s.size())
             ans=max(ans,s[id]+s[id+1]+s[id+2]-solve(s,id+3));
        return dp[id]=ans;
    }
    string stoneGameIII(vector<int>& s) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(s,0);
        cout<<ans;
        if(ans>0)
            return "Alice";
        else if(ans<0)
            return "Bob";
        else
            return "Tie";
    }
};