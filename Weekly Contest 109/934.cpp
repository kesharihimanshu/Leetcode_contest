class Solution {
public:
    vector<pair<int,int>>a,b;
    void solve(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        if(i<0||i>=n||j<0||j>=m||grid[i][j]!=1)
            return ;
        a.push_back({i,j});
        grid[i][j]=2;
        solve(i+1,j,n,m,grid);
        solve(i-1,j,n,m,grid);
        solve(i,j+1,n,m,grid);
        solve(i,j-1,n,m,grid);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        bool fl=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1){
                    solve(i,j,n,m,grid);
                    if(fl)
                    {
                    b=a;
                        fl=false;
                    a.clear();}
            }
        }
        }
        int ans=INT_MAX;
        for(auto &n1:a)
        {
           for(auto &n2:b)
           {
               int u=(abs(n1.first-n2.first)+abs(n1.second-n2.second)-1);
               ans=min(ans,u);
           }
        }
            return ans;
            
    }
};