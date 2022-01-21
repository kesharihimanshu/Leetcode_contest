class Solution {
public:

    bool check(int x,int y,int n,int m)
    {
        if(x<0 || y<0||x>=n||y>=m)
            return false;
        return true;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<int,int>>q;
      
        int n=maze.size(),m=maze[0].size();
  
        q.push({e[0],e[1]});
        int ans=0;
      maze[e[0]][e[1]]='+';
        while(!q.empty())
        {
            int cnt=q.size();
              ans++;
            for(int i=0;i<cnt;i++){
            int x=q.front().first;
            int y=q.front().second;
               q.pop();
                
           if(check(x+1,y,n,m) && maze[x+1][y]=='.')
           {
               if(x+1==n-1||y==0||y==m-1)
               {
                   return ans;
               }
               maze[x+1][y]='+';
               q.push({x+1,y});
           }
                 if(check(x-1,y,n,m) && maze[x-1][y]=='.')
           {
               if(x-1==0||y==0||y==m-1)
               {
                   return ans;
               }
               maze[x-1][y]='+';
               q.push({x-1,y});
           }
                 if(check(x,y+1,n,m) && maze[x][y+1]=='.')
           {
               if(y+1==m-1||x==0||x==n-1)
               {
                   return ans;
               }
               maze[x][y+1]='+';
               q.push({x,y+1});
           }
                 if(check(x,y-1,n,m) && maze[x][y-1]=='.')
           {
               if(y-1==0||x==0||x==n-1)
               {
                   return ans;
               }
               maze[x][y-1]='+';
               q.push({x,y-1});
           }
              
            
                
        }}
        return -1;
    }
};