class Solution {
public:
    double solve(double a,double b)
    {
        double s1=(double)(a+1)/(b+1);
        double s2=(double)(a/b);
        return (s1-s2);
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        priority_queue<array<double,3>>q;
        double ans=0.0;
        for(auto &c:classes)
        {
           ans+=(double)((double)c[0]/(double)c[1]);
            if(c[1]!=c[0])
            q.push({solve(c[0],c[1]),(double)c[0],(double)c[1]});
        }
        
        while(extra-- && !q.empty())
        {
            auto p=q.top();
            q.pop();
            ans+=p[0];
             q.push({solve(p[1]+1,p[2]+1),p[1]+1,p[2]+1});
        }
        return (ans/classes.size());
        
    }
};