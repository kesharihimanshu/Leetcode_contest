class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto &n:nums)
        {
            int last_d=0;
            for(int d=2;d*d<=n;d++)
            {
                if(n%d==0)
                {
                    if(last_d==0)
                        last_d=d;
                    else
                    {
                        last_d=0;
                        break;
                    }
                }
               
            }
             if(last_d!=0)
                {
                if(last_d!=n/last_d){
                    ans+=1+n;
                    ans+=(n/last_d)+last_d;}
                }
            
        }
        return ans;
    }
};