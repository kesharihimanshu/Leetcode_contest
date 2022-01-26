class Solution {
public:
    string reorderSpaces(string text) {
        int cnt=0;
        vector<string>v;
        string temp="";
        for(char &c:text)
        {
            if(c==' ')
            {
                if(temp.size()>0)
                    v.push_back(temp);
                temp="";
                cnt++;
            }
            else
            {
                temp.push_back(c);
            }
        }
        if(temp.size()>0)
                    v.push_back(temp);
         string ans="";
        int n=v.size()-1;
        if(cnt==0)
            return text;
        if(n==0)
        {
            ans+=v[0];
          for(int i=0;i<cnt;i++)
              ans.push_back(' ');
            return ans;
        }
        
        int btw=cnt/n;
        int last=cnt%n;
       
        cout<<cnt<<" "<<n<<" ";
        for(auto &u:v)
        {
            ans+=u;
            for(int i=0;i<btw;i++)
                ans.push_back(' ');
        }
           for(int i=0;i<btw;i++)
                ans.pop_back();
        
         for(int i=0;i<last;i++)
                ans.push_back(' ');
        return ans;
    }
};