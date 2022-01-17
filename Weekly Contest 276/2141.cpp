class Solution {
public:
    #define ll long long
    long long maxRunTime(int n, vector<int>& b) {
        sort(b.begin(),b.end());
        ll sum=0;
        for(int i=0;i<b.size();i++)
            sum+=b[i];
        
        ll high=sum/n;
        ll low=b[0],ans=0;
        while(low<=high)
        {
           
         ll  mid=(high+low)/2;
            ll x=0;
            for(int i=0;i<b.size();i++)
            {
                if(b[i]<=mid)
                    x+=b[i];
                else
                    x+=mid;
            }
            
            ll m=mid*n;
            
            if(m<=x)
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
            
        }
        return ans;
    }
};