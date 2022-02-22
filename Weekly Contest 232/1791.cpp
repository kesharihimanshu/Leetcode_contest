class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        int x=e[0][0];
        if(e[1][0]==x)
            return x;
        else if(e[1][1]==x)
            return x;
           x=e[0][1];
        if(e[1][0]==x)
            return x;
        else if(e[1][1]==x)
            return x;
        return x;
    }
};