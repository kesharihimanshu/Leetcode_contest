class Solution {
public:
    int maxArea(int h, int w, vector<int>& ho, vector<int>& ve) {
        int k=pow(10,9)+7;
         int  a=0,b=0;
        int m=0;
        sort(ho.begin(),ho.end());
        sort(ve.begin(),ve.end());
        for(int i=0;i<ho.size();i++)
        {
            a=max(a,ho[i]-m);
            m=ho[i];
        }
        a=max(a,h-m);
        m=0;
        for(int i=0;i<ve.size();i++)
        {
            b=max(b,ve[i]-m);
            m=ve[i];
        }
        b=max(b,w-m);
        a=a%k;
        b=b%k;
      unsigned  long long int s=(long long)a*b;
        s=s%k;
        return s;
        
    }
};