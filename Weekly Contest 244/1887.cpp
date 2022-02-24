class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int,int>m;
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            s.insert(nums[i]);
        }
        int ans=0;
        auto it=s.begin();
        s.erase(*it);
        int j=1;
        for(auto i:s)
        {
           ans+=j*(m[(i)]); 
            j++;
        }
        return ans;
        
    }
};