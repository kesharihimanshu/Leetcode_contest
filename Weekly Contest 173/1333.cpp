bool com(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first)
        return a.first>b.first;
    return a.second>b.second;
}
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& res, int v, int mp, int md) {
        vector<pair<int,int>>vec;
        for(int i=0;i<res.size();i++){
            if((res[i][2]==v|| v==0) && res[i][3]<=mp && res[i][4]<=md)
                vec.push_back({res[i][1],res[i][0]});
        }
        sort(vec.begin(),vec.end(),com);
        vector<int>ans;
        for(auto ve:vec){
            ans.push_back(ve.second);
        }
        return ans;
    }
};