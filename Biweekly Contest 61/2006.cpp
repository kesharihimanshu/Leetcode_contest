class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto x:nums)
            m[x]++;
        int ans=0;
        for(auto x:nums)
        {
            ans+=m[x+k];
            ans+=m[x-k];
        }
        return ans/2;
            
    }
};