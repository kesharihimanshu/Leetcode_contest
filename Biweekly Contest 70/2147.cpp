class Solution {
public:
    long long mod=1e9+7;
    int numberOfWays(string cor) {
        vector<int>v;
        for(int i=0;i<cor.size();i++)
        {
            if(cor[i]=='S')
                v.push_back(i);
        }
        if(v.size()%2==1||v.size()==0)
            return 0;
        long long ans=1;
        for(int i=2;i<v.size();i+=2)
        {
            long long u=v[i]-v[i-1];
            ans=(ans*u)%mod;
        }
        return ans%mod;
    }
};