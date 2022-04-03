class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
      vector<vector<int>>ans(2);
        map<int,int>m;
        set<int>s1;
        for(auto &v:mat)
        {
          if(m[v[0]]==0)
          {
              s1.insert(v[0]);
          }
            if(s1.find(v[1])!=s1.end())
            {
                s1.erase(v[1]);
            }
            
            m[v[1]]++;
            
        }
        for(auto c:s1){
            ans[0].push_back(c);
        }
        for(auto it:m){
            if(it.second==1)
                ans[1].push_back(it.first);
        }
        return ans;
    }
};