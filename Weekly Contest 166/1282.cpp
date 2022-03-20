class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<g.size();i++)
        {
          m[g[i]].push_back(i);  
        }
        for(auto it:m)
        {
            if(it.second.size()==it.first)
            ans.push_back(it.second);
            else
            {
                int k=it.second.size()/it.first,j=0;
                while(k--)
                {
                    vector<int>v;
                    int y=it.first;
                    while(y--)
                    {
                        v.push_back(it.second[j]);
                        j++;
                    }
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};