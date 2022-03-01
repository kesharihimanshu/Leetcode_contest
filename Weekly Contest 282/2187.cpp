class Solution {
public:
    long long solve(int m,vector<int>& time)
    {
        long long u=0;
        for(int i=0;i<time.size();i++)
        {
            u+=m/time[i];
        }
        return u;
    }
    long long minimumTime(vector<int>& time, int t) {
        sort(time.begin(),time.end());
        if(time.size()==1)
            return (long long) time[0]*t;
        long long low=1,high=(long long)t*time[0];
        long long ans=high;
        while(low<=high)
        {
            long long m=low+(high-low)/2;
            long long s=solve(m,time);
            // cout<<s<<" "<<m<<" ";
            if(s>=t)
            {
                high=m-1;
                ans=m;
            }
            else
            {
                low=m+1;
            }
        }
        return ans;
    }
};