class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++)
            for(int j=1;j<m;j++)
                mat[i][j]+=mat[i][j-1];
        int ans=0;
        for(int j=0;j<m;j++)
        {
            for(int k=j;k<m;k++)
            {
               unordered_map<int,int>mp;
                mp[0]=1;
                int sum=0;
                for(int i=0;i<n;i++)
                {
                     sum+=mat[i][k]-(j>0?mat[i][j-1]:0);
                    ans+=mp[sum-target];
                    mp[sum]++;
                    
                }
            }
        }
        return ans;
    }
};