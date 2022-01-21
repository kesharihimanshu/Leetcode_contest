class Solution {
public:
    bool sumGame(string num) {
        int cnt1=0,cnt2=0;
        int sum1=0,sum2=0;
        int n=num.size();
        
        for(int i=0;i<n;i++)
        {
            if(i<(n/2))
            {
                if(num[i]=='?')
                    cnt1++;
                else
                    sum1+=num[i]-'0';
            }
            else
            {
             if(num[i]=='?')
                    cnt2++;
                else
                    sum2+=num[i]-'0';   
            }
        }
        if((cnt1+cnt2)%2==1)
            return true;
    
      
   int y=min(cnt1,cnt2);
        cnt1-=y;
        cnt2-=y;
        if(cnt1>0)
        {
            if(sum1>sum2)
                return true;
            if(9*(cnt1/2)==sum2-sum1)
                return false;
            return true;
        }
        else
        {
            if(sum2>sum1)
            {
                return true;
            }
            if(9*(cnt2/2)==sum1-sum2)
                return false;
            return true;
        }
        
      return false;
        
        
        
    }
};