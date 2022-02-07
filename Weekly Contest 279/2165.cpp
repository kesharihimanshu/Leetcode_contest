class Solution {
public:
    long long smallestNumber(long long num) {
        string s=to_string(num);
        if(s[0]=='-')
        {
            sort(s.rbegin(),s.rend());
            long long u=stoll(s);
            return -u;
        }
        else
        {
           sort(s.begin(),s.end());
            if(s[0]=='0')
            {
                int i=0;
                while(i<s.size()&&s[i]=='0')
                {
                    i++;
                }
                if(i<s.size())
                swap(s[0],s[i]);
            }
        }
        return stoll(s);
    }
};