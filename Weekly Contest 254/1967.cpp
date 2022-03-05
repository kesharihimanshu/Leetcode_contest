class Solution {
public:
    int numOfStrings(vector<string>& pat, string word) {
        int ans=0;
        for(auto it:pat)
        {
            if(word.find(it)!=string::npos)
                ans++;
        }
        return ans;
    }
};
