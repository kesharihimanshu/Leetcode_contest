class Solution {
public:
    int vis[101][101][201]={};
    
    bool hasValidPath(vector<vector<char>>& grid,int i=0,int j=0,int bal=0) {
       int n=grid.size(),m=grid[0].size();
        bal+=grid[i][j]=='('?1:-1;
        if(bal<0 || vis[i][j][bal])
            return false;
        vis[i][j][bal]=true;
        if(i==n-1 && j==m-1 && bal==0)
            return true;
        if(i<n-1 && (hasValidPath(grid,i+1,j,bal)))
            return true;
        if(j<m-1 && (hasValidPath(grid,i,j+1,bal)))
            return true;
        return false;
        
        
    }
};