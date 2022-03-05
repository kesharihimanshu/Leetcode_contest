class Solution {
public:
    int mod=1e9+7;
    long long solve(long long n,long long u)
    {
        if(n==0)
            return 1;
        if(n==1)
            return u;
        long long a1=solve(n/2,u);
       long long t=(a1*a1)%mod;
        if(n%2)
            t=(t*u)%mod;
        return t;
    }
    int minNonZeroProduct(int p) {
        
        long long u=pow(2,p);
        long long n=u/2-1;
        u-=2;
        long long ans=(u+1)%mod;
         u=u%mod;
        ans=(ans*solve(n,u))%mod;
       
        return ans;
    }
};