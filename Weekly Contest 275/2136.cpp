class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        vector<vector<int>>v;
        int n=grow.size();
        for(int i=0;i<n;i++)
        {
           v.push_back({grow[i],plant[i]}); 
        }
        sort(v.rbegin(),v.rend());
        int cnt=0,ans=0;
        for(int i=0;i<n;i++)
        {
            cnt+=v[i][1];
            ans=max(ans,cnt+v[i][0]);
            
        }
        return ans;
        
    }
};