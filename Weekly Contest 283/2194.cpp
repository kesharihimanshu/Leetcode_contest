class Solution {
public:
    vector<string> cellsInRange(string s) {
        int l=s[1]-'0';
        int r=s[4]-'0';
        int c1=s[0]-'A';
        vector<string>ans;
        int c2=s[3]-'A';
        for(int i=c1;i<=c2;i++){
            for(int j=l;j<=r;j++){
                string a="";
                a.push_back('A'+i);
                a.push_back('0'+j);
                ans.push_back(a);
            }
        }
        return ans;
    }
};