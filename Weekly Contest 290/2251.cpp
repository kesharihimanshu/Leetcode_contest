class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& fl, vector<int>& person) {
       
        vector<int>start,end;
        for(auto i:fl){
            start.push_back(i[0]);
            end.push_back(i[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int>ans;
        for(auto &p:person){
            auto a=upper_bound(start.begin(),start.end(),p)-start.begin();
            auto b=lower_bound(end.begin(),end.end(),p)-end.begin();
            
            ans.push_back(a-b);
        }
        return ans;
    }
};