class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edge) {
        vector<vector<int>>v(n,vector<int>(n,INT_MAX/2-1));
        for(auto &e:edge)
        {
            int u=e[0]-1,b=e[1]-1;
            v[u][b]=1;
            v[b][u]=1;
            
        }
        // min distance from any pair of nodes
        // floyd-marshell
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
                }
            }
        }
        vector<int>ans(n-1,0);
        for(int sub=0; sub<(1<<n);sub++)
        {
            int node=__builtin_popcount(sub);
            int dis=0;
            int e=0;
            for(int i=0;i<n;i++)
            {
                if(sub & (1<<i))
                {
                    for(int j=i+1;j<n;j++)
                    {
                        if(sub & (1<<j))
                        {
                            e+= v[i][j]==1;
                            dis=max(dis,v[i][j]);
                        }
                    }
                }
            }
            // check where the subtree valid or not (reach at every node from any other node) and distance greater than 0; 
            if(e==node-1 && dis>0)
                ans[dis-1]++;
        }
 
        return ans;
        
    }
};





