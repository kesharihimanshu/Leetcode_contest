class Solution {
public:
    bool check(int i,int j,int n,int m)
    {
        if(i<0||j<0 ||j>=m||i>=n)
            return false;
        return true;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int>s;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                s.insert(grid[i][j]);
            }
        }
        for(int l=1;l<=50;l++)
        {
           for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               int a1=i,a2=j-l;
                int b1=i,b2=j+l;
                int c1=i-l,c2=j;
                int d1=i+l,d2=j;
                if(check(a1,a2,n,m)==false && check(b1,b2,n,m)==false && check(c1,c2,n,m)==false && check(d1,d2,n,m)==false)
                {
                    goto end;
                }
                    if(check(a1,a2,n,m) && check(b1,b2,n,m) && check(c1,c2,n,m) && check(d1,d2,n,m)){ 
                int sum=0;
                sum=grid[a1][a2]+grid[b1][b2]+grid[c1][c2]+grid[d1][d2];
                for(int k=1;k<l;k++)
                {
                    sum+=grid[a1-k][a2+k];
                }
                 for(int k=1;k<l;k++)
                {
                    sum+=grid[b1-k][b2-k];
                }
                 for(int k=1;k<l;k++)
                {
                    sum+=grid[a1+k][a2+k];
                }
                 for(int k=1;k<l;k++)
                {
                    sum+=grid[b1+k][b2-k];
                }
                s.insert(sum);}
            }
        }  
        }
        end:
        vector<int>ans;
        vector<int>v;
         for(auto &t:s)
            {
                ans.push_back(t);
            }
        if(s.size()<=3)
        {
           
            reverse(ans.begin(),ans.end());
            return ans;
        }
        else
        {
          for(int i=0;i<3;i++)
          {
              v.push_back(ans.back());
              ans.pop_back();
          }
        }
        return v;
        
    }
};