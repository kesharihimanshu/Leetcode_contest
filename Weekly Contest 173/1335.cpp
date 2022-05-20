class Solution {
public:
    int dp[301][11];
    int n;
    int maxVal=1e7;
    int solve(vector<int>& job, int d,int id){
        if(id==n && d==0)
            return 0;
        if(id==n || d==0)
            return maxVal;
        if(dp[id][d]!=-1)
            return dp[id][d];
        int ans=INT_MAX;
        int mx=0;
        for(int i=id;i<n;i++)
        {
           mx=max(mx,job[i]);
            ans=min(ans,mx+solve(job,d-1,i+1));
        }
        dp[id][d]=ans;
        return ans;
        
    }
    int minDifficulty(vector<int>& job, int d) {
         n=job.size();
        if(n<d)
            return -1;
        if(n==d)
            return (accumulate(job.begin(),job.end(),0));
        memset(dp,-1,sizeof(dp));
        return solve(job,d,0);
    }
};