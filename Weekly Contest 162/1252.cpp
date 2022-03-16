class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int v[m][n];
        memset(v,0,sizeof(v));
        for(auto &in:indices){
            for(int i=0;i<n;i++)
                v[in[0]][i]++;
            for(int i=0;i<m;i++)
                v[i][in[1]]++;
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]%2)
                    ans++;
            }
        }
        return ans;
    }
    
    
};