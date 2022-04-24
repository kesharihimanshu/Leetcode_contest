class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>m;
        for(auto it:nums){
            for(auto i:it){
                m[i]++;
            }
        }
        vector<int>ans;
        int n=nums.size();
        for(auto it:m){
            if(it.second==n)
                ans.push_back(it.first);
        }
        return ans;
    }
};