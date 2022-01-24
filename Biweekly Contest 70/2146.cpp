class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pr, vector<int>& start, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>res;
                vector<vector<int>>ans;
                vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        q.push({start[0],start[1]});
        vector<pair<int,int>>move={{1,0},{-1,0},{0,1},{0,-1}};
        int dis=1;
        while(!q.empty())
        {
          int sz=q.size();
            while(sz--)
            {
                auto p=q.front();
                q.pop();
                if(vis[p.first][p.second]==true)
                    continue;
                if(grid[p.first][p.second]==0)
                {
                   
                    continue;
                }
                vis[p.first][p.second]=true;
                if(grid[p.first][p.second]!=1)
                {
                    int val=grid[p.first][p.second];
                    if(val>=pr[0]&&val<=pr[1])
                    {
                        res.push_back({dis,val,p.first,p.second});
                    }
                }
                for(auto &y:move)
                {
                    int r=y.first+p.first;
                    int c=y.second+p.second;
                   if(r>=0 && r<n && c>=0 && c<m)
                    q.push({r,c});
                }
            }
            dis++;
            if(res.size()>=k)
                break;
        }
        // cout<<dis<<" ";
        sort(res.begin(),res.end());
        for(int i=0;i<min(int(res.size()),int(k));i++)
        {
            ans.push_back({res[i][2],res[i][3]});
        }
        return ans;


    }
};