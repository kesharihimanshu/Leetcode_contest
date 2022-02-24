class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s=s+s;
        vector<char>a(2*n);
        vector<char>b(2*n);
        for(int i=0;i<n+n;i++)
        {
            if(i%2==0)
            {
                a[i]='1';
                b[i]='0';
            }
            else{
                a[i]='0';
                b[i]='1';}
        }
        int ans=INT_MAX;
        int cnt1=0,cnt2=0,j=0;
        for(int i=0;i<n+n;i++)
        {
            if(s[i]!=a[i])
                cnt1++;
            if(s[i]!=b[i])
                cnt2++;
            if(i>=n)
            {
               if(s[j]!=a[j])
                cnt1--;
            if(s[j]!=b[j])
                cnt2--;
                j++;
            }
            if(i>=n-1)
            {
                ans=min(ans,min(cnt1,cnt2));
            }
        }
        return ans;
        
    }
};