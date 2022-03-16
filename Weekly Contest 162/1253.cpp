class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& col) {
        vector<vector<int>>ans;
        int sum=accumulate(col.begin(),col.end(),0);
        if(sum!=(upper+lower))
            return ans;
        int n=col.size();
        vector<vector<int>>v(2,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            if(col[i]==0)
                continue;
          if(col[i]==2){
              v[0][i]=1;
            v[1][i]=1;
              upper--;
              lower--;
          }
            else{
                if(upper>lower)
                {
                   v[0][i]=1;
                    upper--;
                }
                else if(upper==lower)
                {
                    if(upper==0)
                        return ans;
                     v[0][i]=1;
                    upper--;
                }
                else{
                    v[1][i]=1;
                    lower--;
                }
            }
            if(lower<0 || upper<0)
                return ans;
        }
        return v;
    }
};