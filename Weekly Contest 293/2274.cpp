class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& s) {
        sort(s.begin(),s.end());
        int ans=0;
        for(int i=0;i<s.size();i++){
            int u=s[i]-1;
            ans=max(ans,u-bottom+1);
            bottom=s[i]+1;
        }
        ans=max(top-bottom+1,ans);
        return ans;
    }
};