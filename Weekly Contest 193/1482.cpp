class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
     int n=b.size();
        if(m*k>n)
            return -1;
        int i=1,j=*max_element(b.begin(),b.end()),ans=0;
    
        while(i<=j)
        {
            int mi=(i+j)/2;
            int u=k;
            int res=0;
            for(int w=0;w<n;w++)
            {
                if(b[w]<=mi)
                {
                    u--;
                    if(u==0)
                    {
                        res++;
                        u=k;
                    }
                }
                else
                    u=k;
            }
            
            if(res>=m)
            {
                
                ans=mi;
                j=mi-1;
            }
            else
            {
                i=mi+1;
            }
            
        }
        return ans;
        
    }
};