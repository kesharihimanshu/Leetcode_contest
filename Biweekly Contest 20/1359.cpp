class Solution {
public:
    #define ll long long
    int mod=1e9+7;
    int countOrders(int n) {
        int m=2*n;
        vector<ll>v(n+1);
        v[1]=1;
        for(int i=2;i<=n;i++)
        {
            v[i]=(v[i-1]*i)%mod;
        }
        ll ans=1;
        for(int i=1;i<m;i=i+2)
        {
           ans=(ans*i)%mod; 
        }
        ans=(ans*v[n])%mod;
        return ans;
    }
};