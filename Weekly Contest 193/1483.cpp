 // BINARY LIFTING
class TreeAncestor {
public:
//THIS QUESTION IS BASED ON BINARY LIFTING TECHNIQUE
   int dp[50000][16];// MAKE A LCA 2-D ARRAY TO STORE THE PARENTS IN POWER OF 2;
  
    TreeAncestor(int n, vector<int>& p) {
         memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=p[i];
        }
        int u=log2(n);
        for(int j=1;j<=u;j++)
        {
            for(int i=0;i<n;i++)// WE JUST MAKE THE 2^Jth PARENT BY USING 2^(J-1)th.
            {
                if(dp[i][j-1]!=-1)
                {
                    int par=dp[i][j-1];
                    dp[i][j]=dp[par][j-1];
                }
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        while(k>0)
        {
            int i=log2(k);
            node=dp[node][i];
            if(node==-1)
                return node;
            k-=(1<<i);
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */