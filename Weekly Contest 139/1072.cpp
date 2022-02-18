class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>m;
        for(auto &x:matrix)
        {
           string s;
            int top=x[0];
            for(auto &v:x)
            {
                if(top==v)
                    s+='1';
                else
                    s+='0';
            }
            m[s]++;
            
        }
        int ans=0;
        for(auto [key,val]:m)
            ans=max(ans,val);
        return ans;
    }
};