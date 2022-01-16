class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0,n=s.size(),j=0;
       unordered_map<char,int>mp;
        int i=0;
        for(auto &y:s)
        {
            if(y=='a'||y=='b'||y=='c')
                mp[y]++;
          
            if(mp.size()==3)
            {
               ans+=(n-i);
                cout<<i<<" ";
                while(mp.size()==3)
                {
                   if(s[j]=='a'||s[j]=='b'||s[j]=='c')
                mp[s[j]]--;
                    if(mp[s[j]]==0)
                        mp.erase(s[j]);
                    j++;
                    if(mp.size()==3)
                        ans+=n-i;
                }
            }
            i++;
        }
        return ans;
    }
};