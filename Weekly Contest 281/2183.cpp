class Solution {
public:
    // ((n1*n2)%k==0) IS EQUAL TO (GCD(n1,k)*(GCD(n2,k))%k==0)
    
    long long countPairs(vector<int>& nums, int k) {
        long long ans=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            int u=__gcd(k,nums[i]);
            for(auto it:m)
            {
                if((((long long)it.first*(long long)u))%k==0)
                    ans+=it.second;
            }
            m[u]++;
        }
        return ans;
    }
};