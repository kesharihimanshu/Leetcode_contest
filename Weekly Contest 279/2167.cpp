class Solution {
public:
    int minimumTime(string s) {
        int n=s.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        left[0]=s[0]-'0';
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
                left[i]=left[i-1];
            else
            {
                left[i]=min(i+1,left[i-1]+2);
            }
        }
        right[n-1]=s[n-1]-'0';
        for(int i=n-2;i>=0;i--)
        {
          if(s[i]=='0')  
          {
              right[i]=right[i+1];
          }
            else
            {
                right[i]=min(right[i+1]+2,n-i);
            }
        }
        int ans=min(left[n-1],right[0]);
        for(int i=0;i<n-1;i++)
        {
            ans=min(ans,left[i]+right[i+1]);
        }
        return ans;
    }
};