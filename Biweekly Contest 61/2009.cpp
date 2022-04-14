class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums)
            mp[it]++;
        vector<int>v;
        for(auto it:mp){
            v.push_back(it.first);
        }
        int u=nums.size()-v.size();
        // cout<<u<<" ";
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<v.size();i++){
            auto it=lower_bound(v.begin(),v.end(),v[i]+n-1)-v.begin();
            // cout<<it<<" ";
            if(it==v.size())
                it--;
            if(v[it]>v[i]+n-1)
                it--;
            if(ans>(v.size()-it-1+i))
                ans=v.size()-it-1+i;
        }
        return ans+u;
    }
};