class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string>v;
        int u=0,i=0;
       while(i<s.size())
       {
           string h="";
           while(i<s.size() && s[i]!=' ')
           {
             h.push_back(s[i]);
               i++;
           }
           int y=h.size();
           u=max(u,y);
           v.push_back(h);
           i++;
       }
        vector<string>ans;
      
           
            for(int j=0;j<u;j++)
            {
                 string h="";
                 for(int i=0;i<v.size();i++)
            {
                   if(v[i].size()<=j)
                       h.push_back(' ');
                     else
                         h.push_back(v[i][j]);
                
            }
                while(h.back()==' ')
                {
                    h.pop_back();
                }
                ans.push_back(h);
        }
        return ans;
        
    }
};