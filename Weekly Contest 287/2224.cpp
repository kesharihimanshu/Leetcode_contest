class Solution {
public:
    int convertTime(string a, string b) {
        int h=stoi(a.substr(0,2))-stoi(b.substr(0,2));
        int m=stoi(a.substr(3,2))-stoi(b.substr(3,2));
        h=-h;
        m=-m;
        int u=h*60+m;
        // cout<<h<<" "<<m;
        int ans=0;
        ans+=u/60;
        u=u%60;
        ans+=u/15;
        u=u%15;
        ans+=u/5;
        u=u%5;
        ans+=u;
        return ans;
    }
};