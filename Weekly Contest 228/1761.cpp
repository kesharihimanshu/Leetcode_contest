class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>v(n+1,vector<int>(n+1,0));
        vector<int>degree(n+1,0);
        for(auto &e:edges){
            v[e[0]][e[1]]=1;
            v[e[1]][e[0]]=1;
            degree[e[0]]++;
            degree[e[1]]++;
        }
        int ans=1e5;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(v[i][j]==0)
                    continue;
                for(int k=j+1;k<=n;k++){
                    if(v[j][k] && v[k][i])
                    {
                        ans=min(ans,degree[i]+degree[j]+degree[k]-6);
                    }
                }
            }
        }
        return ans;
    }
};