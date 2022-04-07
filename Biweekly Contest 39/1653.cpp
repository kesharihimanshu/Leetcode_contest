class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>a(n);
        vector<int>b(n);
        if(s[0]=='a')
            a[0]=1;
        else
            a[0]=0;
        for(int i=1;i<n;i++)
        {
           a[i]=a[i-1]+(s[i]=='a'?1:0); 
        }
        b[n-1]=(s[n-1]=='b'?1:0);
        for(int i=n-2;i>=0;i--)
        {
            b[i]=b[i+1]+(s[i]=='b'?1:0);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int x=(s[i]=='a'?a[i]-1:a[i]);
            int y=(s[i]=='b'?b[i]-1:b[i]);
            
            int d1=i-x;
            int d2=(n-i-1-y);
            // cout<<d1<<d2<<" ";
            ans=min(ans,d1+d2);
        }
        return ans;
        
    }
};