class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<int>ans;
        int a=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
          a+=nums[i];
           sum-=nums[i];
            ans.push_back(nums[i]);
            if(a>sum)
                return ans;
        }
        return ans;
    }
};