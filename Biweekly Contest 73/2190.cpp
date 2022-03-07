class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int>m;
    
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key)
            {
                if(i<nums.size()-1)
                    m[nums[i+1]]++;
            }
        }
        int ans=0,mx=0;
        for(auto it:m)
        {
            if(it.second>mx)
            {
                ans=it.first;
                mx=it.second;
            }
        }
        return ans;
    }
};