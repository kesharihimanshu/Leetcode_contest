class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>m;
        for(auto &a:arr)
        {
            m[a]++;
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        for(auto it:m)
        {
            for(int i=0;i<it.second;i++)
            {
                q.push({it.second,it.first});
            }
        }
        while(k--)
        {
            q.pop();
        }
        if(q.empty())
            return 0;
        int ans=1,u=q.top()[1];
        while(!q.empty())
        {
           if(q.top()[1]==u)
               q.pop();
            else{
                u=q.top()[1];
                ans++;
                q.pop();
            }
        }
        return ans;
    }
};