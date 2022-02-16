class Solution {
public:
    int maxScore(string s) {
        int r=0;
        for(auto c:s)
        {
            if(c=='1')
                r++;
            
        }
        int ans=0,a=0;
        if(s[0]=='0')
            a++;
        else
            r--;
         ans=max(ans,a+r);
        for(int i=1;i<s.size()-1;i++)
        {
            if(s[i]=='1')
                r--;
            else
                a++;
            ans=max(ans,a+r);
        }
        return ans;
    }
};