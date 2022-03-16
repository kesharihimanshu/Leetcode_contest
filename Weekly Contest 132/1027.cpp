class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
         int n=a.size();
        if(n<=2)
            return n;
        int ans=0;
        vector<vector<int>>v(n,vector<int>(1002,0));
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<i;j++)
          {
              int diff=a[i]-a[j];
              diff+=500;
              if(v[j][diff]!=0)
              {
                 
                  v[i][diff]=1+v[j][diff];
              }
              else
                  v[i][diff]=2;
              if(ans<v[i][diff])
                  ans=v[i][diff];
             
          }
        }
        return ans;
    }
};