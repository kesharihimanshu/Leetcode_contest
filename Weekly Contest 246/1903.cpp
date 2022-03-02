class Solution {
public:
    string largestOddNumber(string s) {
        for(int i=s.size()-1;i>=0;i--)
        {
            int u=s[i]-'0';
            if(u%2!=0)
            {
                return s.substr(0,i+1);
            }
        }
        return "";
    }
};