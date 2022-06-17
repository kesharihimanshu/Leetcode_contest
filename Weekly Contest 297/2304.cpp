class Solution {
public:
    int dp[52][52];
    int solve(int x,int y,int n,int m,vector<vector<int>>& grid, vector<vector<int>>& moveCost){
        if(x==(n-1)){
            return grid[x][y];}
        if(dp[x][y]!=-1)return dp[x][y];
        int ans=INT_MAX;
      
            for(int j=0;j<m;j++)
            ans=min(ans,solve(x+1,j,n,m,grid,moveCost)+moveCost[grid[x][y]][j]+grid[x][y]);
            
        
       
        return dp[x][y]=ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
      int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,solve(0,i,n,m,grid,moveCost));
        }
        return ans;
    }
};