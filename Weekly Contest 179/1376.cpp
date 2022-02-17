class Solution {
public:
    unordered_map<int,vector<int>>m;
    int solve( vector<int>& in,int node)
    {
        int time=0;
        for(auto &v:m[node])
        {
            time=max(time,solve(in,v));
        }
        return time+in[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& man, vector<int>& in) {
        for(int i=0;i<n;i++)
        {
            if(man[i]!=-1)
            {
               m[man[i]].push_back(i); 
            }
        }
        return solve(in,headID);
    }
};