class Solution {
public:
    int mod=1e9+7;

    int countTexts(string s) {
      vector<long long >dp(s.size()+1);
        dp[0]=1;
        for(int i=0;i<s.size();i++){
            dp[i+1]=dp[i];
            if(i>0 && s[i-1]==s[i]){
                dp[i+1]=(dp[i+1]+dp[i-1])%mod;
                if(i>1&& s[i]==s[i-2])
                {
                    dp[i+1]=(dp[i+1]+dp[i-2])%mod;
                    if(i>2 && s[i]==s[i-3] && (s[i]=='7'||s[i]=='9'))
                        dp[i+1]=(dp[i+1]+dp[i-3])%mod;
                }
            }
        }
        return dp[s.size()];
    }
};