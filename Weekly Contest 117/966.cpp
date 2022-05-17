class Solution {
public:
    vector<string> spellchecker(vector<string>& a, vector<string>& q) {
        vector<string>ans;
        unordered_map<string,int>m;
        unordered_map<string,string>mp;
        for(auto u:a)
        {
            m[u]++;
            string temp=u;
            transform(temp.begin(),temp.end(),temp.begin(),::tolower);
              if(mp.count(temp)==0)
            mp[temp]=u;
           
            for(int i=0;i<temp.size();i++)
            {
                char c=temp[i];
                if(c=='a'|| c=='e'||c=='i'|| c=='o'||c=='u')
                   temp[i]='*';
            }
          
            if(mp.count(temp)==0)
            mp[temp]=u;
           
        }
        for(auto u:q)
        {
            if(m.count(u))
            {
                ans.push_back(u);
                continue;
            }
              string temp=u;
            transform(temp.begin(),temp.end(),temp.begin(),::tolower);
            if(mp.count(temp))
            {
               ans.push_back(mp[temp]);
                continue; 
            }
             for(int i=0;i<temp.size();i++)
            {
                char c=temp[i];
                if(c=='a'|| c=='e'||c=='i'|| c=='o'||c=='u')
                   temp[i]='*';
            }
              if(mp.count(temp))
            {
               ans.push_back(mp[temp]);
                continue; 
            }
            ans.push_back("");
            
           
        }
        return ans;
    }
};