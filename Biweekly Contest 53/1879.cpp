class Solution {
public:
    int dp[15][1<<15];// MAINLY MY DP FOR MEMOISATION 
    int solve(int i,int j,vector<int>& nums1,vector<int>& nums2,int n)
    {
        if(i>=n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=0;k<n;k++)
        {
            if((j & (1<<k))==0)
            {
               ans=min(ans,solve(i+1,(j|(1<<k)),nums1,nums2,n)+(nums1[i]^nums2[k])); 
            }
        }
        return (dp[i][j]=ans);
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));// INISALIZE MY DP ARRAY
        int n=nums1.size();
    return solve(0,0,nums1,nums2,n);
    }
};