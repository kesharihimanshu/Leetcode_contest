class Solution {
public:
    int minFlips(string s) {
        int ans=0;
        char st='0';
        for(int i=0;i<s.size();i++)
        {
          if(st!=s[i])
          {
              ans++;
              st=st=='0'?'1':'0';
          }
        }
        return ans;
    }
};