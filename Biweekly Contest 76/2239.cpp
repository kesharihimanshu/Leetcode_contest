class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
       int cn=INT_MAX,ans=0;
        for(auto &n:nums)
        {
            int u=abs(n);
            if(cn>u)
            {
                ans=n;
                cn=u;
            }
            else if(cn==u)
            {
                ans=max(ans,n);
            }
        }
        return ans;
    }
};