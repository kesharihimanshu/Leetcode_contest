class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rec, vector<vector<int>>& points) {
       vector<vector<int>>v(101);
        for(auto &r:rec){
            v[r[1]].push_back(r[0]);
        }
        for(int i=0;i<101;i++){
            sort(v[i].begin(),v[i].end());
        }
        vector<int>ans;
        for(auto &p:points){
            int sum=0;
            for(int i=p[1];i<101;i++){
                auto it=lower_bound(v[i].begin(),v[i].end(),p[0])-v[i].begin();
                sum+=v[i].size()-it;
            }
            ans.push_back(sum);
        }
        return ans;
        
    }
};