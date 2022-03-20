class Solution {
public:
    bool solve(int m,vector<int>& nums, int th)
    {
        int u=0;
        for(auto &c:nums)
        {
            u+=c/m;
            if(c%m)
                u++;
        }
        return u<=th;
    }
    int smallestDivisor(vector<int>& nums, int th) {
        int ans=0;
        int low=1,high=1000000;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(solve(mid,nums,th)){
                ans=mid;
                high=mid-1;}
            else
                low=mid+1;
            
        }
    return ans;
    }
};