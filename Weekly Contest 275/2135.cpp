class Solution {
public:
    int wordCount(vector<string>& st, vector<string>& t) {
        map<string,int>m;
        for(auto h:st)
        {
            sort(h.begin(),h.end());
            m[h]++;
        }
        int ans=0;
        for(auto h:t)
        {
           sort(h.begin(),h.end());
            for(int i=0;i<h.size();i++)
            {
                string u=h;
                u.erase(u.begin()+i);
                if(m[u]>0)
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
        
    }
};