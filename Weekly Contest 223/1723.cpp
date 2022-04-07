class Solution {
     int ans=INT_MAX;
    void solve(int id,vector<int>& jobs,vector<int>&cost,int k,int n)
    {
        if(id==n)
        {
            int sum=0;
            for(auto &t:cost)
                sum=max(sum,t);
            ans=min(ans,sum);
            return;
        }
        unordered_set<int>seen;
        for(int i=0;i<k;i++)
        {
            if(seen.find(cost[i])!=seen.end()) continue;
            if(cost[i]+jobs[id]>=ans) continue;
            seen.insert(cost[i]);
            cost[i]+=jobs[id];
            solve(id+1,jobs,cost,k,n);
            cost[i]-=jobs[id];
        }
        seen.clear();
   
    }
    
public:
  
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int>cost(k,0);
        int n=jobs.size();
        solve(0,jobs,cost,k,n);
        cost.clear();
        return ans;
    }
};