class Solution {
public:
    map<int,int>m;
    int minDays(int n) {
        if(n<=1)
            return n;
        if(m[n]>0)
            return m[n];
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        if(n%2==0)
            a=1+minDays(n/2);
        if(n%3==0)
            b=1+minDays(n/3);
        if((n%2)!=0 || (n%3)!=0)
            c=1+minDays(n-1);
        m[n]=min(a,min(b,c));
        return m[n];
    }
};
