class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n=cars.size();
        vector<double>ans(n,-1.0);
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && cars[i][1]<=cars[s.top()][1])
            {
                s.pop();
            }
            while(!s.empty())
            {
                double coll=(double)((double)(cars[s.top()][0]-cars[i][0])/(double)(cars[i][1]-cars[s.top()][1]));
                if(coll<=ans[s.top()] || ans[s.top()]==-1)
                {
                    ans[i]=coll;
                    break;
                }
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};