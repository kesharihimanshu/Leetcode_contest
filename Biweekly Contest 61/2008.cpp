bool com(vector<int>&a,vector<int>&b){
    if(a[1]!=b[1])
        return a[1]<b[1];
    return a[1]<b[0];
}
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        long long ans=0;
        sort(rides.begin(),rides.end(),com);
        vector<long long>dp(n+1,0);
        int prev=1;
        for(auto &it:rides)
        {
            while(prev<it[1])
            {
                dp[prev]=max(dp[prev-1],dp[prev]);
                prev++;
            }
          dp[it[1]]=max(dp[it[1]],dp[it[0]]+it[1]-it[0]+it[2]);
            // cout<<dp[it[1]]<<" ";
        }
      
        while(prev<=n)
            {
                dp[prev]=max(dp[prev-1],dp[prev]);
                prev++;
            }
        return dp[n];
    }
};