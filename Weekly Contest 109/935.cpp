class Solution {
public:
    int knightDialer(int n) {
        if(n==1)
            return 10;
        int mod=1e9+7;
        vector<long long int>tmp(10);
        vector<long long int>v(10,1);
       
        for(int i=1;i<n;i++)
        {
           tmp[0]=(v[4]+v[6])%mod;
            tmp[1]=(v[6]+v[8])%mod;
            tmp[2]=(v[7]+v[9])%mod;
            tmp[3]=(v[4]+v[8])%mod;
            tmp[4]=(v[0]+v[3]+v[9])%mod;
            tmp[6]=(v[0]+v[1]+v[7])%mod;
            tmp[7]=(v[2]+v[6])%mod;
            tmp[8]=(v[1]+v[3])%mod;
            tmp[9]=(v[2]+v[4])%mod;
            for(int j=0;j<10;j++)
                v[j]=tmp[j];
            
        }
    long long int sum=0;
        for(int i=0;i<10;i++)
        {
            sum=(sum+v[i])%mod;
        }
        return sum;
    }
};