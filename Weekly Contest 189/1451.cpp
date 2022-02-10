class Solution {
public:
    string arrangeWords(string text) {
        map<int,vector<string>>m;
        string s="";
        for(int i=0;i<text.size();i++)
        {
            if(text[i]==' ')
            {
                m[s.size()].push_back(s);
                s="";
            }
            else{
                text[i]=tolower(text[i]);
                s.push_back(text[i]);
            }
        }
           m[s.size()].push_back(s);
        s="";
        for(auto it:m)
        {
            for(int i=0;i<it.second.size();i++)
            { 
                
                s+=it.second[i];
                s.push_back(' ');
            }
        }
        s[0]=toupper(s[0]);
        s.pop_back();
        return s;
    }
};