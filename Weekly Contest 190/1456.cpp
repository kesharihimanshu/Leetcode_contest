class Solution {
public:
    bool is(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            return true;
            return false;
    }
    int maxVowels(string s, int k) {
        int j=0;
        int ans=0;
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
           if(is(s[i]))
               cnt++;
            if(i-j+1==k)
            {
                ans=max(ans,cnt);
                if(is(s[j]))
                    cnt--;
                j++;
            }
        }
        return ans;
    }
};