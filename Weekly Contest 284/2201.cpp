class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& arti, vector<vector<int>>& dig) {
        set<pair<int,int>>s;
        for(auto d:dig){
            s.insert({d[0],d[1]});
        }
        int ans=0;
        for(auto &v:arti){
            bool fl=true;
          for(int i=v[0];i<=v[2];i++)
          {
              for(int j=v[1];j<=v[3];j++){
                  {
                      if(s.count({i,j})==0)
                      {
                          fl=false;
                          break;
                      }
                  }
                  if(fl==false)
                      break;
              }
          }
            if(fl)
                ans++;
        }
        return ans;
    }
};