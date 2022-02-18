class Solution {
public:
    int mod=pow(10,9)+7;
    int maxPerformance(int n, vector<int>& s, vector<int>& ef, int k) {
        vector<pair<long long,long long>>v;
        for(int i=0;i<s.size();i++)
        {
            v.push_back({ef[i],s[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<>>q;
        long long speed=0;
        long long ans=0;
        for(int i=0;i<v.size();i++)
        {
            q.push(v[i].second);
            speed+=v[i].second;
            if(q.size()>k)
            {
                speed-=q.top();
                q.pop();
            }
           
            long long h=speed*v[i].first;
           
            ans=max(ans,h);
           
        }
                
ans=ans%mod;
        return ans;
    }
};