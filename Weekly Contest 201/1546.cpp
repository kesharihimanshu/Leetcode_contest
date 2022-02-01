class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int t) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int ans=0,mx=-1;
        for(int i=0;i<nums.size()-1;i++)
        {
            int u=nums[i]-t;
            if(mp.find(u)!=mp.end())
            {
                if(mp[u]>=mx)
                {
                    mx=i;
                    ans++;
                }
                
            }
            mp[nums[i]]=i;
           
            
            nums[i+1]+=nums[i];
        }
        int u=nums.back()-t;
          if(mp.find(u)!=mp.end())
            {
                if(mp[u]>=mx)
                {
                   
                    ans++;
                }
                
            }
        return ans;
    }
};