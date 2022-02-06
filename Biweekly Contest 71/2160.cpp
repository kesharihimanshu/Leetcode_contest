class Solution {
public:
    int minimumSum(int num) {
        string s=to_string(num);
        sort(s.begin(),s.end());
        string a,b;
        for(int i=0;i<s.size();i++)
        {
            if(i%2==0)
            {
                a.push_back(s[i]);
                
            }
            else
                b.push_back(s[i]);
        }
        return stoi(a)+stoi(b);
    }
};