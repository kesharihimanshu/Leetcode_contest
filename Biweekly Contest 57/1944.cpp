class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int n=h.size()-1;
        stack<int>s;
        vector<int>ans;
        for(int i=n;i>=0;i--)
        {
            int u=0;
            while(!s.empty()&& h[s.top()]<h[i])
            {
                u++;
                s.pop();
            }
            if(!s.empty())
                u++;
           ans.push_back(u);
            s.push(i);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};