class Solution {
public:
    int countMatches(vector<vector<string>>& items, string r1, string val) {
        int ans=0,u=0;
        if(r1=="type")
        {
            u=0;
        }
        else if(r1=="color")
            u=1;
        else
            u=2;
        for(auto v:items)
        {
            if(v[u]==val)
                ans++;
        }
        return ans;
        
    }
};