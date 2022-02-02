class Solution {
public:
// we have to maximise y1+y1+|x1-x2|, where x1<=x2 so,
    // maximise the (y2+x2+y1-x1)
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        priority_queue<pair<int,int>>q;
        int ans=INT_MIN;
        for(int i=0;i<p.size();i++)
        {
          
              while((!q.empty()) && p[i][0]-q.top().second>k) q.pop();
             if(!q.empty())
                ans = max(ans, (q.top().first + p[i][0] + p[i][1]));
          
            q.push({p[i][1] - p[i][0], p[i][0]});
         
        }
        return ans;
    }
};

