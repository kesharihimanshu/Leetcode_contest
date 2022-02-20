class Solution {
public:
    string repeatLimitedString(string s, int r) {
        vector<int>v(26,0);
        for(auto c:s)
        {
            v[c-'a']++;
        }
       priority_queue<pair<char,int>>q;
        for(int i=25;i>=0;i--)
        {
            if(v[i]>0)
            {
                q.push({'a'+i,v[i]});
            }
        }
        string ans;
        while(!q.empty())
        {
            auto [c,cnt]=q.top();
            q.pop();
            int ub=min(cnt,r);
            for(int i=0;i<ub;i++)
                ans.push_back(c);
            cnt-=ub;
            if(cnt>0)
            {
                if(q.empty())
                    return ans;
                else
                {
                    auto [ch,cnt1]=q.top();
                    q.pop();
                    ans.push_back(ch);
                    cnt1--;
                    if(cnt1>0)
                    {
                        q.push({ch,cnt1});
                    }
                    q.push({c,cnt});
                }
            }
            
        }
        return ans;
    }
};