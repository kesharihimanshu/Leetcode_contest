class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& road) {
        map<int,int>m;
        vector<vector<bool>>v(n,vector<bool>(n,false));
        for(auto &a:road)
        {
            m[a[0]]++;
            m[a[1]]++;
            v[a[0]][a[1]]=true;
            v[a[1]][a[0]]=true;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int u=m[i]+m[j];
                if(v[i][j])
                    u--;
                ans=max(ans,u);
                
            }
        }
        return ans;
    }
};