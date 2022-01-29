class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
         map<int,int>mp;
        for(auto &n:nums1)
        {
            m[n]++;
        }
         for(auto &n:nums2)
        {
            mp[n]++;
        }
         int ans=0;
       for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                long long u=(long long)nums1[i]*(long long)nums1[i];
                if(u%nums2[j]!=0)
                    continue;
                u=u/nums2[j];
                // cout<<u<<" ";
                if(mp[u]>0)
                {
                    ans+=mp[u];
                    if(u==nums2[j])
                        ans--;
                }
            }
        }
        // cout<<ans<<" ";
      
          for(int i=0;i<nums2.size();i++)
        {
            for(int j=0;j<nums1.size();j++)
            {
                long long u=(long long)nums2[i]*(long long)nums2[i];
                if(u%nums1[j]!=0)
                    continue;
                u=u/nums1[j];
                if(m[u]>0)
                {
                    ans+=m[u];
                    if(u==nums1[j])
                        ans--;
                }
            }
        }
        return (ans/2);
        
    }
};