class Solution {
public:
    int countHomogenous(string s) {
        int mod=1e9+7;
        long long ans=0;
        int j=1;
        char c=s[0];
        ans=1;
        for(int i=1;i<s.size();i++){
            if(c==s[i])
                j++;
            else
                j=1;
            c=s[i];
            ans=(ans+j)%mod;
            
        }
        return ans;
    }
};