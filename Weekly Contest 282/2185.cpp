class Solution {
public:
    int prefixCount(vector<string>& w, string pref) {
        int n=pref.size();
        int ans=0;
        for(int i=0;i<w.size();i++)
        {
          if(w[i].substr(0,n)==pref)
              ans++;
        }
        return ans;
    }
};