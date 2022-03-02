class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int sh=stoi(loginTime.substr(0,2));
        int se=stoi(loginTime.substr(3,2));
        int oh=stoi(logoutTime.substr(0,2));
        int oe=stoi(logoutTime.substr(3,2));
    
        if(sh<oh)
        {
            if(se%15){
          if(se<15)
              se=15;
            else if(se<30)
                se=30;
            else if(se<45)
                se=45;
            else
            {
                se=0;
                sh++;
            }}
          int t1=sh*60+se;
        int t2=oh*60+oe;
            int u=t2-t1;
            return (u/15);
        }
        else if(sh==oh && se<oe)
        {
            if(se%15){
          if(se<15)
              se=15;
            else if(se<30)
                se=30;
            else if(se<45)
                se=45;
            else
            {
                se=0;
                sh++;
            } }
               int t1=sh*60+se;
        int t2=oh*60+oe;
            if(t1>t2)
                return 0;
            int u=t2-t1;
            return (u/15);
        }
        if(se%15){
        if(se<15)
              se=15;
            else if(se<30)
                se=30;
            else if(se<45)
                se=45;
            else
            {
                se=0;
                sh++;
            } }
        int t1=sh*60+se;
        int t2=oh*60+oe;
        int u=24*60-t1;
        u+=t2;
        return u/15;
            
        
        
    }
};