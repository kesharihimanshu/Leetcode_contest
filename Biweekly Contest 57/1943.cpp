class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& seg) {
       vector<vector<long long>>ans;
        vector<vector<long long>>a;
        // in this 2Darrary we put all critical points because we have to select the all the segment
        for(auto &s:seg)
        {
            a.push_back({s[0],1,s[2]});// for adding in the total
             a.push_back({s[1],-1,s[2]});// for substracting the colour from the total
        }
        sort(a.begin(),a.end());
        long long t=a[0][2];
        for(int i=1;i<a.size();i++)
        {
            if(t>0 && a[i][0]>a[i-1][0])
    // if total >0 && current pos is greater than previous then we push that segment into our ans vector;
            {
                ans.push_back({a[i-1][0],a[i][0],t});
                
            }
            t+=a[i][2]*a[i][1];// calculation of colour;
        }
        return ans;
    }
};