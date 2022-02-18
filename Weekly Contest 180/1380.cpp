class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),sum=INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            sum=INT_MAX;
            for(int j=0;j<m;j++)
            {
              sum=min(sum,mat[i][j]);  
            }
            mp[sum]++;
        }
        sum=INT_MIN;
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            sum=INT_MIN;
            for(int j=0;j<n;j++)
            {
              sum=max(sum,mat[j][i]);  
            }
            mp[sum]++;
            if(mp[sum]>1)
                ans.push_back(sum);
        }
        return ans;
    }
};