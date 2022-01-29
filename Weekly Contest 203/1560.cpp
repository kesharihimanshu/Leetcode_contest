class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& r) {
        int s=r[0],e=r.back();
        vector<int>ans;
        if(s<e)
        {
            for(int i=s;i<=e;i++)
            {
                ans.push_back(i);
            }
        }
        else if(s>e)
        {
            for(int i=1;i<=e;
               i++)
            {
                ans.push_back(i);
            }
            for(int i=s;i<=n;i++)
                ans.push_back(i);
        }
        else
            ans.push_back(s);
        return ans;
    }
};