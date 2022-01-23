class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int>v(26);
        for(auto c:s)
        {
            v[c-'a']++;    
        }
        int u=v[s[0]-'a'];
        for(int i=1;i<s.size();i++)
        {
            if(v[s[i]-'a']!=u)
                return false;
            
        }
        return true;
        
        
    }
};