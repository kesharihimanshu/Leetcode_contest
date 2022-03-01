class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tire, int change, int nl) {
         int n=tire.size();
        vector<vector<int>>wc(n,vector<int>(20,2e9));
        // without changing the tire.
        // simply in this ec vector we store the taking the laps without changing the tire by max of 19th.
        
        for(int i=0;i<n;i++)
        {
            wc[i][1]=tire[i][0];
            
            for(int j=2;j<20;j++)
            {
                if((long long)wc[i][j-1]*tire[i][1]>=2e9)
                    break;
                wc[i][j]=wc[i][j-1]*tire[i][1];
            }
              //Beacuse we have to calculate the the total time so we take the prefix sum
            for(int j=2;j<20;j++)
            {
                if((long long)wc[i][j-1]+wc[i][j]>=2e9)
                    break;
                wc[i][j]+=wc[i][j-1];
            }
            
        }
        // taking the dp for calculating the dp[x]->min amount time it will take to done the nl number of laps.
        vector<int>dp(nl+1,2e9);
        for(auto &t:tire)
            dp[1]=min(dp[1],t[0]);
      
        for(int i=1;i<=nl;i++)
        {
           if(i<20)
           {
               //if i<20 this is chance of min time by using single tire also.
               
               for(int j=0;j<n;j++)
                   dp[i]=min(dp[i],wc[j][i]);
           }
            
            for(int j=i-1;j>0 && j>=i-18;j--)
                dp[i]=min(dp[i],dp[j]+change+dp[i-j]);
        }
        return dp[nl];
        
        
    }
};


