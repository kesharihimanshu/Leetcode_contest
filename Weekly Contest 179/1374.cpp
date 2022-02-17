class Solution {
public:
    string generateTheString(int n) {
        string h="";
         for(int i=0;i<n;i++)
                h.push_back('a');
        if(n&1)
        {
            return h;
        }
        h.pop_back();
        h.push_back('b');
        return h;
    }
};