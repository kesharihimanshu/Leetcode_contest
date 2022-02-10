class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& f) {
        vector<unordered_set<string>>v(f.size());
        int n=f.size();
        for(int i=0;i<n;i++)
        {
            for(auto &s:f[i])
            {
                v[i].insert(s);
            }
        }
         vector<int>ans;
        bool fl1,fl;
        for(int i=0;i<n;i++)
        {
            fl1=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
              fl=1;
                for(auto &s:f[i])
                {
                    if(v[j].find(s)==v[j].end())
                    {
                        fl=0;
                        break;
                    }
                }
                if(fl)
                {
                   fl1=1;
                    break;
                }
            }
            if(fl1==0)
                ans.push_back(i);
        }
        return ans;
        
    }
};