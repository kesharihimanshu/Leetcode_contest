class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>>v(row,vector<int>(col,0));
          vector<vector<int>>a(row,vector<int>(col,0));
        int low=0,high=cells.size()-1,ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            v=a;
            for(int i=0;i<=mid;i++)
                v[cells[i][0]-1][cells[i][1]-1]=1;
            queue<pair<int,int>>q;
            for(int i=0;i<col;i++)
            {
                if(v[0][i]==0)
                {
                    q.push({0,i});
                }}
                bool ok=0;
                int x[4]={0,0,-1,1};
                int y[4]={1,-1,0,0};
                while(!q.empty())
                {
                    auto u=q.front();q.pop();
                    int r=u.first,c=u.second;
                    for(int j=0;j<4;j++)
                    {
                        int f=r+x[j],g=c+y[j];
                        if(f>=0 && f<row && g>=0 && g<col && v[f][g]==0)
                        {
                            if(f==row-1)
                            {
                                ok=true;
                                break;
                            }
                            v[f][g]=1;
                            q.push({f,g});
                        }
                    }
                    if(ok)
                        break;
                }
            if(ok)
            {
                ans=mid+1;low=mid+1;
            }
            else
                high=mid-1;
            }
        return ans;
    }
};