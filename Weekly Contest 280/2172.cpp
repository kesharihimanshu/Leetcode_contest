class Solution {
public:
    int maximumANDSum(vector<int>& nums, int n) {
        while(nums.size()<(2*n))
        {
            nums.push_back(0);// we just make numsers are euqal for all slots
        }
        int h=1<<(nums.size());
        h--;
        vector<int>dp(h+1,0);// dp for bitmask
        for(int i=1;i<=h;i++)
        {
            int slot=(__builtin_popcount(i)+1)/2;
            for(int j=0;j<nums.size();j++)
            {
                if(i &(1<<j))
                {
                    dp[i]=max(dp[i],dp[i^(1<<j)]+(nums[j]&slot));
                }
            }
        }
        return dp[h];
    }
};