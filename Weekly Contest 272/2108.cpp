class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto s:words)
        {
            string a=s;
            reverse(a.begin(),a.end());
            if(a==s)
                return s;
        }
        return "";
    }
};