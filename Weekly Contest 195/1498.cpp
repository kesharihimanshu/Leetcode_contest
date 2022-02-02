class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod=1e9+7;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int a[n];
        a[0]=1;
        for(int i=1;i<n;i++)
        {
            a[i]=(a[i-1]*2)%mod;// nc1+nc2+...+ncn=2^n;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            
            int id=upper_bound(nums.begin(),nums.end(),(target-nums[i]))-nums.begin();
            id--;
            // cout<<id<<" ";
            if(id<i)
                return ans;
            int f=id-i;
            ans+=a[f];
            ans=ans%mod;
        }
        return ans;
    }
};