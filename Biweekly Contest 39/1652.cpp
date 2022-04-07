class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>v;
        v=code;
        for(auto &c:code)
        {
            v.push_back(c);
        }
         for(auto &c:code)
        {
            v.push_back(c);
        }
        
        vector<int>p;
        p.push_back(v[0]);
        for(int i=1;i<v.size();i++)
        {
            p.push_back(p[i-1]+v[i]);
        }
        vector<int>ans;
       if(k<0){
        for(int i=code.size();i<2*code.size();i++)
        {
            ans.push_back(p[i-1]-p[i+k-1]);
        }}
        else{
            for(int i=code.size();i<2*code.size();i++)
        {
            ans.push_back(p[i+k]-p[i]);
        }
        }
        return ans;
    }
};