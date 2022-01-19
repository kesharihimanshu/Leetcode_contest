class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int x=0;
        for(auto &i:spaces)
        {
            ans+=s.substr(x,i-x);
            ans.push_back(' ');
            x=i;
        }
        ans+=s.substr(x);
        return ans;
    }
};