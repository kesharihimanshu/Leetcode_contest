class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int sum=0;
        for(int i=0;i<a.size();i++)
            sum+=a[i];
        int b=a.size()-k;
        int u=0,ans=INT_MAX,j=0;
        for(int i=0;i<a.size();i++)
        {
            u+=a[i];
            if(i-j+1==b)
            {
              if(ans>u)
                  ans=u;
                u-=a[j];
                j++;
            }
            
        }
        if(ans==INT_MAX)
            ans=0;
        return sum-ans;
    }
};