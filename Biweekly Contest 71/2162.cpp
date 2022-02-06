class Solution {
public:
    int minCostSetTime(int startAt, int mc, int pc, int ts) {
        int min=ts/60;
        int sec=ts%60;
        if(min==100)
        {
            min--;
            sec+=60;
        }
        string a="";
        if(min<10)
        {
            a.push_back('0');
            a+=to_string(min);
            if(sec<10)
                a.push_back('0');
            a+=to_string(sec);
        }else
        {
            a+=to_string(min); 
             if(sec<10)
                a.push_back('0');
            a+=to_string(sec);
        }
        cout<<a<<" ";
        int cur=startAt;
        int ans1=0,i=0;
        while(a[i]=='0')
        {
            i++;
        }
        for(;i<4;i++)
        {
           if(a[i]-'0'==cur)
           {
               ans1+=pc;
           }
            else{
                ans1+=pc;
                ans1+=mc;
                cur=a[i]-'0';
            }
        }
        if(sec>=40)
        {
            return ans1;
        }
        min--;
        sec+=60;
        a="";
         if(min<10)
        {
            a.push_back('0');
            a+=to_string(min);
            if(sec<10)
                a.push_back('0');
            a+=to_string(sec);
        }else
        {
            a+=to_string(min); 
             if(sec<10)
                a.push_back('0');
            a+=to_string(sec);
        }
        cout<<a<<" ";
          cur=startAt;
        int ans2=0;
        i=0;
        while(a[i]=='0')
        {
            i++;
        }
        for(;i<4;i++)
        {
           if(a[i]-'0'==cur)
           {
               ans2+=pc;
           }
            else{
                ans2+=pc;
                ans2+=mc;
                cur=a[i]-'0';
            }
        }
        // cout<<ans1<<" "<<ans2;
       if(ans1<=ans2)
           return ans1;
        return ans2;
    }
};