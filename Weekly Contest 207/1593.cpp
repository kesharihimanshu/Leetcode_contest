class Solution {
public:
    int ans=0;
    map<string,int>m;
    void solve(int id,string s,int cnt)
    {
        if(id>=s.size())
        {
            ans=max(ans,cnt);
            return;
        }
        string t="";
        for(int i=id;i<s.size();i++)
        {
            t.push_back(s[i]);
            if(m[t]==0)
            {
               
                m[t]++;
                solve(i+1,s,cnt+1);
                m[t]--;
            }
          
            
        }
    }
    int maxUniqueSplit(string s) {
       
        solve(0,s,0);
        return ans;
        
    }
};