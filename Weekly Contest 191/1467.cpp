class Solution {
public:
    double total=0,fav=0;
    // total-> total outcomes
    // fav-> fav outcomes
 static  double fact(int n)
    {
        if(n==0)
            return 1.0;
        if(n<3)
            return n;
       else
       {
           return n*fact(n-1);
       }
    }
    void solve(vector<int>& ball,int id,int col1,int col2,int cnt1,int cnt2,double prm1,double prm2)
    {
        if(cnt1==0 && cnt2==0)
        {
           // cout<<total;
            total+=(prm1*prm2);
            if(col1==col2)
            {
                fav+=(prm1*prm2);
            }
        }
        else if(cnt1>=0 && cnt2>=0)
        {
            for(int b1=0,b2=ball[id];b2>=0;b2--,b1++)
            {
                double f1=fact(b1),f2=fact(b2);
                solve(ball,id+1,col1+(b1>0),col2+(b2>0),cnt1-b1,cnt2-b2,prm1/ f1,prm2/ f2);
            }
        }
        
    }
    double getProbability(vector<int>& ball) {
        int sum=accumulate(ball.begin(),ball.end(),0);// total balls
        solve(ball,0,0,0,sum/2,sum/2,fact(sum/2),fact(sum/2));
     
        return (fav/total);
    }
};

