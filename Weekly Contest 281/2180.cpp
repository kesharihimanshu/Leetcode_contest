class Solution {
public:
    int countEven(int num) {
        int ans=0;
        for(int i=1;i<=num;i++)
        {
            int sum=0,u=i;
            while(u)
            {
                sum+=u%10;
                u=u/10;
            }
            if(sum%2==0)
                ans++;
        }
        return ans;
    }
};