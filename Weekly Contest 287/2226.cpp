class Solution {
public:
    bool solve(vector<int>& candy, long long k,int m)
    {
        if(m==0)
            return true;
        long long u=0;
        for(auto &t:candy){
            u+=t/m;
        }
        return u>=k;
    }
    int maximumCandies(vector<int>& candy, long long k) {
        int low=0,high=0;
        for(int i=0;i<candy.size();i++)
        {
            high=max(high,candy[i]);
        }
        int ans=0;
        while(low<=high)
        {
            int m=(low+high)/2;
            
            if(solve(candy,k,m))
            {
                ans=m;
                low=m+1;
            }
            else
                high=m-1;
        }
        return ans;
        
    }
};