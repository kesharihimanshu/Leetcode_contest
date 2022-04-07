class Solution {
public:
    bool ans=false;
    void solve(vector<int>& qt, vector<int>&v,int i)
    {
        if(i>=qt.size()||ans)
        {
            ans=true;
            return;
        }
        for(int j=0;j<v.size();j++)
        {
            int n=v[j];
            if(n>=qt[i])
            {
                v[j]-=qt[i];
                solve(qt,v,i+1);
                v[j]+=qt[i];
            }
        }
        return;
    }
    bool canDistribute(vector<int>& nums, vector<int>& qt) {
        unordered_map<int,int>m;
        for(auto &q:nums)
            m[q]++;
        vector<int>v;
        for(auto it:m)
        {
            v.push_back(it.second);
        }
        sort(qt.rbegin(),qt.rend());
        solve(qt,v,0);
        return ans;
        
            
    }
};