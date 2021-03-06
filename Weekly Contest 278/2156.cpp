class Solution {
public:
    // power function for calculationof power that not contain in long long
    long long power(int n,int r,long long mod)
    {
        if(r==0)
            return 1;
        if(r==1)
        {
            return (n%mod);
        }
        long long ans=1;
        long long know=power(n,r/2,mod)%mod;
        if(r%2==1)
        {
            ans=(ans*n)%mod;
        }
        return (ans*((know*know)%mod))%mod;
    }
    string subStrHash(string s, int p, int mod, int k, int h) {
     long long ans=0;
        reverse(s.begin(),s.end());
        string fans;
        for(int i=0;i<s.size();i++)
        {
            if(i<k)
            {
              ans=(ans+((s[i]-'a'+1)*power(p,k-1-i,mod))%mod)%mod;
                continue;
            }
            if(ans==h)
            {
                string temp=s.substr(i-k,k);
                reverse(temp.begin(),temp.end());
                fans=temp;
            }
            ans=(ans+mod-((s[i-k]-'a'+1)*power(p,k-1,mod))%mod)%mod;
            ans=(ans*p)%mod;
            ans=(ans+(s[i]-'a'+1))%mod;
        }
          if(ans==h)
            {
                string temp=s.substr(s.size()-k,k);
                reverse(temp.begin(),temp.end());
                fans=temp;
            }
        return fans;
        
        
    }
};