class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2);
        unordered_map<int,int>m,mp;
        for(auto n:nums2)
        {
            m[n]++;
        }
        for(int i=0;i<nums1.size();i++)
        {
            if(m[nums1[i]]==0){
                ans[0].push_back(nums1[i]);
                m[nums1[i]]++;}
            mp[nums1[i]]++;
                
        }
        for(auto l:nums2)
        {
            if(mp[l]==0)
                ans[1].push_back(l);
            mp[l]++;
        }
        return ans;
    }
};