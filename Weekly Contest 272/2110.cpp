class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long cnt=0,ans=0;
        for(int i=1;i<p.size();i++)
        {
            if(p[i-1]==p[i]+1)
            {
                cnt++;
                ans+=cnt;
            }
            else
                cnt=0;
           
           
        }
        ans+=p.size();
        return ans;
        
        
    }
};