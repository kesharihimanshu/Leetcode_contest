class Solution {
public:
    int minOperationsMaxProfit(vector<int>& c, int bc, int r) {
        int rot=0,ans=rot,tot=0;
        int i=0,mx=INT_MIN,num=0;
        for( i=0;i<c.size();i++)
        {
          rot=i+1;
            tot+=c[i];
            if(tot>=4)
            {
                num+=4;
                tot-=4;
            }
            else
            {
                num+=tot;
                tot=0;
            }
            int u=num*bc-r*rot;
           
            if(u>mx)
            {
                mx=u;
                ans=rot;
            }
        }
        while(tot>0)
        {
            rot=i+1;
            
            if(tot>=4)
            {
                num+=4;
                tot-=4;
            }
            else
            {
                num+=tot;
                tot=0;
            }
            int u=num*bc-r*rot;
           
            if(u>mx)
            {
                mx=u;
                ans=rot;
            }
            i++;
            
        }
        if(mx<=0)
            return -1;
        return ans;
    }
};