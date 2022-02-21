class Solution {
public:
    int ans=0,m=INT_MAX;
    void solve(vector<int>& b, vector<int>& t, int target,int sum,int id)
    {
        if(id>=t.size())
        {
            int u=abs(sum-target);
            if(u<m)
            {
                ans=sum;
                m=u;
            }
            else if(u==m){
                if(sum<ans)
                    ans=sum;
            }
            return ;
        }
        for(int i=id;i<t.size();i++)
        {
            solve(b,t,target,sum,i+1);
            solve(b,t,target,sum+t[i],i+1);
            solve(b,t,target,sum+t[i]+t[i],i+1);
        }
        return ;
    }
    int closestCost(vector<int>& b, vector<int>& t, int target) {
        for(int i=0;i<b.size();i++)
        {
            solve(b,t,target,b[i],0);
        }
        return ans;
    }
};