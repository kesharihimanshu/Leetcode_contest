class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        int ma=INT_MIN,mi=INT_MAX,sum=0,c=0,tot=0;
        for(int i=0;i<a.size();i++)
        {
            sum+=a[i];
            c+=a[i];
            ma=max(ma,sum);
            sum=max(sum,0);
            tot+=a[i];
            mi=min(mi,c);
            c=min(c,0);
        }
        if(tot==mi)
            return ma;
        return max(tot-mi,ma);
            
    }
};