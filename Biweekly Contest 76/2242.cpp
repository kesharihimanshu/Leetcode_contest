
bool com(pair<int,int>a,pair<int,int>b){
    return a.second>b.second;
}
class Solution {
public:
   
    int maximumScore(vector<int>& sc, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>>m;
      
        for(auto it:edges){
            m[it[0]].push_back({it[1],sc[it[1]]});
             m[it[1]].push_back({it[0],sc[it[0]]});
        }
        for(int i=0;i<sc.size();i++)
        {
            sort(m[i].begin(),m[i].end(),com);
        }
     
        int ans=-1;
        for(auto it:edges){
            int u=it[0],v=it[1];
            for(int i=0;i<min(3,(int)m[u].size());i++){
                int x=m[u][i].first;
                if(x==v)continue;
                for(int j=0;j<min(3,(int)m[v].size());j++){
                    int y=m[v][j].first;
                    if(y==u||y==x)
                        continue;
                    ans=max(ans,sc[u]+sc[v]+sc[x]+sc[y]);
                }
            }
        }
        return ans;
    }
};