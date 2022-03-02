class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<vector<int>>v(n+1,vector<int>(101,0));
        for(int i=1;i<=n;i++)
        {
           v[i]=v[i-1];
            v[i][nums[i-1]]++;
        }
        vector<int>ans;
        for(auto q:queries)
        {
            auto l=q[0]+1;
            auto r=q[1]+1;
            vector<int>temp;
            for(int i=0;i<=100;i++)
            {
                if(v[r][i]-v[l-1][i]>0)
                    temp.push_back(i);
            }
            int f=106;
            for(int i=1;i<temp.size();i++)
            {
                f=min(f,temp[i]-temp[i-1]);
            }
            if(f==106)
                f=-1;
             ans.push_back(f);
        }
        return ans;
    }
};