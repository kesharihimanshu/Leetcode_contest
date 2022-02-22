class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt=0,a=-1,b=-1;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                cnt++;
                if(cnt>2)
                    return false;
                if(a==-1)
                {
                    a=i;
                }
                else if(b==-1)
                {
                    b=i;
                }
            }
                
        }
        if(cnt==1)
            return false;
        if(cnt==0)
            return 1;
        if(s1[a]!=s2[b]||s1[b]!=s2[a])
            return 0;
        return 1;
        
    }
};