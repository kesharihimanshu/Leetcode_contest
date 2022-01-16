class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>>v;
        for(auto h:arr)
        {
            bitset<32>a(h);
            int u=a.count();
            v.push_back({u,h});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=v[i][1];
        }
        return arr;
    }
};