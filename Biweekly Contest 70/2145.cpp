class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int cnt=0,ans=0;
        sort(cost.begin(),cost.end());
        for(int i=cost.size()-1;i>=0;i--)
        {
            if(cnt==2)
            {
                cnt=0;
                continue;
                
            }
            else
            {
                ans+=cost[i];
                cnt++;
            }
        }
        return ans;
    }
};