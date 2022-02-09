class Solution {
public:
    int isPrefixOfWord(string a, string s) {
        int m=s.size();
        int i=0,ans=0;
        while(i<a.size())
        {
            string h="";
            ans++;
            while(i<a.size() && a[i]!=' ')
            {
                h.push_back(a[i]);
                i++;
            }
            if(h.size()>=m)
            {
                if(h.substr(0,m)==s)
                    return ans;
            }
            i++;
        }
        return -1;
    }
};