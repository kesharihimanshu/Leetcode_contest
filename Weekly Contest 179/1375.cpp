class Solution {
public:
    int numTimesAllBlue(vector<int>& f) {
        int ans=0;
        int mx=0;
        for(int i=0;i<f.size();i++)
        {
            mx=max(mx,f[i]);
            if(mx==i+1)
                ans++;
            
        }
        return ans;
    }
};