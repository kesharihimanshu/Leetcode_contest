class Solution {
public:
    vector<int> decode(vector<int>& en, int first) {
        vector<int>ans;
        ans.push_back(first);
        for(auto u:en)
        {
            first=first^u;
         ans.push_back(first) ;  
        }
        return ans;
    }
};