class Solution {
public:
    unordered_map<int,int>m;
    int dp[6001][2];
    int solve(int i,bool back,int a,int b,int x)
    {
        if(i==x)
            return 0;
        if(i<0 || m[i]>0 || i>6000)
        {
            return 1e9;
        }
        if(dp[i][back]!=-1)
            return dp[i][back];
        dp[i][back]=1+solve(i+a,0,a,b,x);
        if(!back){
            dp[i][back]=min(dp[i][back],1+solve(i-b,1,a,b,x));
        }
        return dp[i][back];
        
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(auto f:forbidden)
            m[f]++;
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,a,b,x);
        if(ans>1e9)
            return -1;
        return ans;
    }
};