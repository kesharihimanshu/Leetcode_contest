class Solution {
public:
    int dp[101][101];
    int n;
    int len(int cnt)
    {
        if(cnt==1)
            return 0;
        else if(cnt<10)
            return 1;
        else if(cnt<100)
            return 2;
        else
            return 3;
    }
    int solve(int i,int k,string &s)
    {
        if(k<0) return 101;
        if(i>=n || n-i<=k) return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans=101;
        int cnt=0;
        int frq[26]={0};
        for(int j=i;j<n;j++)
        {
            frq[s[j]-'a']++;
            cnt=max(cnt,frq[s[j]-'a']);
            ans=min(ans,1+len(cnt)+solve(j+1,k-(j-i+1-cnt),s));
            
        }
        dp[i][k]=ans;
        return ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        n=s.size();
        return solve(0,k,s);
    }
};