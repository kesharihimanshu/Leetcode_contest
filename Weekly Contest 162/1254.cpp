class Solution {
public:
     int ans=0;
    bool flag;
    void solve(vector<vector<int>>& a,int i,int j,int n,int m)
    {
             
        if(a[i][j]==1||i<0||j<0||i>=n||j>=m)
            return;
           a[i][j]=1;
             if(i==0||i==n-1||j==0||j==m-1)  
             {
                 flag=false;
                 return;
             }
        
   solve(a,i+1,j,n,m);
        solve(a,i,j+1,n,m);
        solve(a,i,j-1,n,m);
        solve(a,i-1,j,n,m);
        return;
         
      
        
    }
    int closedIsland(vector<vector<int>>& a) {
  
       
        int n=a.size(),m=a[0].size();
        
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                flag=true;
                if(a[i][j]==0)
                {
                   solve(a,i,j,n,m);
                 if(flag)
                     ans++;
                }
            }
        }
       
        return ans;
    }
};