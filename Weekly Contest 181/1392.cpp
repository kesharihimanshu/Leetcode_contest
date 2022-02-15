class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>v(n,0);
       
        for(int i=1;i<n;i++)
        {
            int j=v[i-1];
            while(j>0 && s[i]!=s[j])
                j=v[j-1];
            if(s[i]==s[j])
                j++;
            v[i]=j;
            
        }
        return s.substr(0,v[n-1]);
    }
};