class Solution {
public:
    string restoreString(string s, vector<int>& in) {
        string ans=s;
        for(int i=0;i<in.size();i++)
        {
            ans[in[i]]=s[i];
        }
        return ans;
    }
};