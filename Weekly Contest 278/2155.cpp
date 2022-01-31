class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n+1,0);
        vector<int>b(n+1,0);
        for(int i=1;i<=n;i++)
        {
    if(nums[i-1]==0)
        a[i]=1+a[i-1];
            else
                a[i]=a[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==1)
            {
                b[i]=b[i+1]+1;
            }
            else
                b[i]=b[i+1];
        }
        vector<int>ans;
        int mx=0;
        for(int i=0;i<=n;i++)
        {
            int u=a[i]+b[i];
            if(mx<u)
            {
                ans.clear();
                mx=u;
                ans.push_back(i);
            }
            else if(mx==u)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};