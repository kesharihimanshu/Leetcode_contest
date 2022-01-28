class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        string a="../";
        string b="./";
       
        for(auto &s:logs)
        {
           if(s==a)
           {
               ans--;
               ans=max(0,ans);
           }
            else if(s==b)
            {
                continue;
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};