class Solution {
public:
    int inf=1e7;
    int dp[101][21][101];
    int solve(vector<int>& h, vector<vector<int>>& cost, int m, int n, int target,int id,int nbr,int left)
    {
        if(id>=m)
        {
            if(nbr==target)
                return 0;
            return inf;
        }
        if(nbr>target)
            return inf;
        
        if(dp[id][left][nbr]!=-1)
            return dp[id][left][nbr];
       if(h[id]==0)
       {
          
           int ans=inf;
           for(int i=1;i<=n;i++)
           {  
                int nb=nbr;
               if(i!=left)
                   nb++;
               ans=min(ans,cost[id][i-1]+solve(h,cost,m,n,target,id+1,nb,i));
           }
           return dp[id][left][nbr]=ans;
       }
        else
        {
             int nb=nbr;
               if(h[id]!=left)
                   nb++; 
            int ans=solve(h,cost,m,n,target,id+1,nb,h[id]);
            return dp[id][left][nbr]=ans;
        }
    }
    int minCost(vector<int>& h, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(h,cost,m,n,target,0,0,0);
        if(ans==inf)
            return -1;
        return ans;
    }
};