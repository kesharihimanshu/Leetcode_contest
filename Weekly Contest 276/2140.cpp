class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long>v(n+1,0);
        long long ans=0;
        for(int i=n-1;i>=0;i--)
        {
            long long temp=q[i][0];
            if(i+q[i][1]+1<n)
            {
               temp+=v[i+q[i][1]+1]; 
            }
            v[i]=max(temp,v[i+1]);
            ans=max(v[i],ans);
        }
        return ans;
        
    }
};