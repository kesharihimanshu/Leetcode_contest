class Solution {
public:
   
    bool isvalid(int i,int j,int n,int m)
    {
        if(i<0||j<0||i>=n||j>=m)
            return false;
        return true;
    }
    void dfs(int x,int y,vector<vector<int>>& grid,vector<vector<bool>>&vis)
    {
        if(vis[x][y])
            return;
        
        vis[x][y]=1;
        int up=0,left=0,right=0,down=0;
        if(grid[x][y]==1)
            left=right=1;
        else if(grid[x][y]==2)
            up=down=1;
        else if(grid[x][y]==3)
            left=down=1;
        else if(grid[x][y]==4)
            down=right=1;
        else if(grid[x][y]==5)
            left=up=1;
        else
            up=right=1;
        int n=grid.size(),m=grid[0].size();
         if(up)
        {
            int new_x=x-1,new_y=y;           
    if(isvalid(new_x,new_y,n,m) && (grid[new_x][new_y]==2||grid[new_x][new_y]==3||grid[new_x][new_y]==4)) 
                dfs(new_x,new_y,grid,vis);
        }
        if(down)
        {
            int new_x=x+1,new_y=y;
            if(isvalid(new_x,new_y,n,m) && (grid[new_x][new_y]==2||grid[new_x][new_y]==5||grid[new_x][new_y]==6))
                dfs(new_x,new_y,grid,vis);
        }
        if(right)
        {
            int new_x=x,new_y=y+1;
            if(isvalid(new_x,new_y,n,m) && (grid[new_x][new_y]==1||grid[new_x][new_y]==5||grid[new_x][new_y]==3))
             dfs(new_x,new_y,grid,vis);
        }
        if(left)
        {
            int new_x=x,new_y=y-1;
            if(isvalid(new_x,new_y,n,m) && (grid[new_x][new_y]==1||grid[new_x][new_y]==4||grid[new_x][new_y]==6))
               dfs(new_x,new_y,grid,vis);
        }
            
        
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        dfs(0,0,grid,vis);
        return vis[n-1][m-1];
    }
};
 