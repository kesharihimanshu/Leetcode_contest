class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<vector<int>>q;
        int n=grid.size(),m=grid[0].size();
        q.push({0,0,k,0});
        vector<vector<int>>vis(n,vector<int>(m,-1));
        while(!q.empty())
        {
           
                auto v=q.front();
                q.pop();
            int x,y;
            x=v[0];
            y=v[1];
             if(x<0 || x>=n||y<0||y>=m)
                    continue;
                if(x==n-1 && y==m-1)
                    return v[3];
             if(grid[x][y]==1)
                {
                    if(v[2]>0)
                        v[2]--;
                    else
                        continue;
                }
            if(vis[x][y]!=-1 && vis[x][y]>=v[2])
                continue;
            vis[x][y]=v[2];
            q.push({x+1,y,v[2],v[3]+1});
             q.push({x-1,y,v[2],v[3]+1});
             q.push({x,y-1,v[2],v[3]+1});
             q.push({x,y+1,v[2],v[3]+1});
                
               
           
        }
        return -1;
    }
};