class Solution {
public:
    int countTriples(int n) {
        map<int,int>m;
        for(int i=1;i<=n;i++)
        {
            m[i*i]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int y=i*i+j*j;
                if(m[y])
                    ans++;
            }
        }
        return ans;
    }
};