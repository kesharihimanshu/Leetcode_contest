class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int d1=0,d2=0;
        int h=high,l=low;
        while(l)
        {
            d1++;
            l=l/10;
        }
        while(h)
        {
            d2++;
            h=h/10;
        }
       
        vector<int>ans;
        for(int i=d1;i<=d2;i++)
        {
            long long k=0,add=0;
            for(int j=1;j<=i;j++)
            {
                k=k*10+j;
                add=add*10+1;
            }
            if(k<=high && k>=low)
                ans.push_back(k);
            
            for(int j=1;j<=9-i;j++)
            {
                   k+=add;
               if(k<=high && k>=low)
                ans.push_back(k); 
             
            }
        }
        return ans;
    }
};