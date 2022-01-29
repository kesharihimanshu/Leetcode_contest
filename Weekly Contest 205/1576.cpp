class Solution {
public:
    string modifyString(string s) {
        int n=s.size();
        if(n==1)
        {
            if(s[0]=='?')
                s[0]='a';
            return s;
        }
        if(s[0]=='?')
        {
            if(s[1]=='a')
                s[0]='b';
            else
            {
                s[0]='a';
            }
        }
        s.push_back('a');
        for(int i=1;i<n;i++)
        {
            if(s[i]=='?')
            {
                if(s[i-1]!='r' && s[i+1]!='r')
                {
                    s[i]='r';
                }
                else if(s[i-1]=='r')
                {
                    if(s[i+1]=='i')
                    s[i]='u';
                    else
                        s[i]='i';
                }
                else if(s[i+1]=='r')
                {
                    if(s[i-1]=='i')
                        s[i]='p';
                    else
                        s[i]='i';
                    
                }
            }
        }
        s.pop_back();
        return s;
    }
};