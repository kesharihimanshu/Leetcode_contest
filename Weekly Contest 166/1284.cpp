class Solution {
public:
    map<string,bool>mp;
    queue<vector<vector<int>>>q;
    int n,m;
    bool good(vector<vector<int>>&b){
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(b[i][j])
                    return false;
            }
        }
        return true;
    }
    string mapping(vector<vector<int>>&b)
    {
        string s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                s.push_back('0'+b[i][j]);
            }
            s.push_back('$');
        }
        return s;
    }
    void solve(vector<vector<int>>&b){
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                auto temp=b;
                temp[i][j]=!temp[i][j];
                if(i-1>=0)
                    temp[i-1][j]=!temp[i-1][j];
                if(j-1>=0)
                    temp[i][j-1]=!temp[i][j-1];
                 if(i+1<n)
                    temp[i+1][j]=!temp[i+1][j];
                if(j+1<m)
                    temp[i][j+1]=!temp[i][j+1];
                string s=mapping(temp);
                if(mp.find(s)==mp.end())
                {
                    mp[s]=true;
                    q.push(temp);
                }
                
            }
        }
    }
    
    int minFlips(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        q.push(mat);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto a=q.front();q.pop();
               if(good(a))
                   return level;
                solve(a);
            }
            level++;
        }
        return -1;
    }
};