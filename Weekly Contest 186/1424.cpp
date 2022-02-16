class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int mx=0;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                m[i+j].push_back(nums[i][j]);
                mx=max(mx,i+j);
            }
        }
        vector<int>ans;
        for(int i=0;i<=mx;i++)
        {
              for(int j=m[i].size()-1;j>=0;j--)
              {
                  ans.push_back(m[i][j]);
              }
        }
        return ans;
    }
};