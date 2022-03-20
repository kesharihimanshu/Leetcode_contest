class Solution {
public:
    int subtractProductAndSum(int n) {
        if(n==0)
            return 0;
        long long p=1;
        int sum=0;
        while(n)
        {
          int s=n%10;
            n=n/10;
            p=p*s;
            sum+=s;
        }
        return p-sum;
    }
};