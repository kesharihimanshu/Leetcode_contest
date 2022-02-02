class Solution {
public:
    bool isPathCrossing(string path) {
        int a=0,b=0;
        map<pair<int,int>,int>m;
        m[{a,b}]++;
        for(auto &c:path)
        {
            if(c=='N')
            {
                b++;
            }
            else if(c=='E')
                a++;
            else if(c=='S')
                b--;
            else
                a--;
            if(m[{a,b}]>0)
                return true;
            m[{a,b}]++;
        }
        return false;
    }
};