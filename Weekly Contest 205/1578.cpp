class Solution {
public:
    int minCost(string col, vector<int>& n) {
        int ans=0;
        int cost=n[0];
        char ch=col[0];
        for(int i=1;i<col.size();i++)
        {
            if(col[i]==ch)
            {
                ans+=min(n[i],cost);
                if(cost<n[i])
                {
                  ch=col[i];
                    cost=n[i];
                }
            }
            else
            {
                ch=col[i];
                cost=n[i];
            }
        }
        return ans;
    }
};