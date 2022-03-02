class Solution {
public:
    int k=0;
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,int n,int m)
    {
        if(i<0||j<0||i>=n||j>=m||grid2[i][j]==0)
            return;
        if(grid1[i][j]==0)
            k=0;
        grid2[i][j]=0;
        dfs(grid1,grid2,i+1,j,n,m);
        dfs(grid1,grid2,i-1,j,n,m);
        dfs(grid1,grid2,i,j+1,n,m);
        dfs(grid1,grid2,i,j-1,n,m);
        return;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;
        int n=grid1.size(),m=grid1[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j])
                {
                    k=1;
                    dfs(grid1,grid2,i,j,n,m);
                    if(k)
                        ans++;
                }
            }
        }
        return ans;
    }
};