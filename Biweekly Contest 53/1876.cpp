class Solution {
public:
    int countGoodSubstrings(string s) {
        map<char,int>m;
        int j=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            if(i-j+1==3)
            {
              if(m.size()==3)
                  ans++;
                m[s[j]]--;
                if(m[s[j]]==0)
                    m.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};