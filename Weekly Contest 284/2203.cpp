class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>a,b;
    void solve(int u,vector<long long>&s){
        priority_queue<pair<long long,int>>q;
        for(int i=0;i<s.size();i++)
        {
            if(i==u){
                s[i]=0;
                continue;}
            s[i]=1e18;
        }
        q.push({0,u});
        while(!q.empty()){
            auto [w,v]=q.top();
            q.pop();
            if(w>s[v])
                continue;
            for(auto &p:a[v]){
                int f=p.first;
                int se=p.second;
                s[f]=min(s[f],w+se);
                q.push({w+se,f});
            }
        }
        
        
    }
      void solve1(int u,vector<long long>&s){
        priority_queue<pair<long long,int>>q;
        for(int i=0;i<s.size();i++)
        {
            if(i==u){
                s[i]=0;
                continue;}
            s[i]=1e18;
        }
        q.push({0,u});
        while(!q.empty()){
            auto [w,v]=q.top();
            q.pop();
            if(w>s[v])
                continue;
            for(auto &p:b[v]){
                int f=p.first;
                int se=p.second;
                 s[f]=min(s[f],w+se);
                q.push({w+se,f});
            }
        }
        
        
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        for(auto &e:edges){
            a[e[0]].push_back({e[1],e[2]});
            b[e[1]].push_back({e[0],e[2]});
        }
        vector<long long>sol1(n+1,0);
        vector<long long>sol2(n+1,0);
        vector<long long>sol3(n+1,0);
        solve(src1,sol1);
        solve(src2,sol2);
        solve1(dest,sol3);
      
        long long ans=1e18;
        for(int i=0;i<=n;i++){
            ans=min(ans,(long long)sol1[i]+sol2[i]+sol3[i]);
        }
        if(ans==1e18)
            return -1;
            
        return ans;
        
    }
};