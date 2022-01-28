class Solution {
public:
    vector<int>dp;
    int ans=0,m;
    void solve(vector<vector<int>>& r,int id,int temp)
    {
        if(id>=r.size())
        {
            for(int i=0;i<m;i++)
            {
                if(dp[i]!=0)
                {
                    return;
                }
            }
            ans=max(ans,temp);
            return;
        }
        for(int i=id;i<r.size();i++)
        {
            dp[r[i][0]]--;
            dp[r[i][1]]++;
            solve(r,i+1,temp+1);
            dp[r[i][0]]++;
            dp[r[i][1]]--;
            
        }
         for(int i=0;i<m;i++)
            {
                if(dp[i]!=0)
                {
                    return;
                }
            }
            ans=max(ans,temp);
            return;
        
    }
    int maximumRequests(int n, vector<vector<int>>& r) {
        dp.resize(n,0);
        m=n;
        solve(r,0,0);
        return ans;
        
    }
};