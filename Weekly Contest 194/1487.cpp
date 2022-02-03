class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
              map<string,int> mp;
        vector<string> ans;
        for(auto &n:names){
            if(mp.find(n)!=mp.end()){
                string x=n+'('+to_string(mp[n])+')';
                while(mp.find(x)!=mp.end()){
                  mp[n]++;
                  x=n+'('+to_string(mp[n])+')';   
                 }
                ans.push_back(x);
                mp[x]++;
                mp[n]++;
            }
            else {
                ans.push_back(n);
                 mp[n]++;
                 }
        }
        return ans;
    }
};