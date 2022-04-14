class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        vector<int>ans;
        if(a.size()&1)
            return {};
        unordered_map<int,int>m;
        int mx=0;
        for(auto x:a){
            m[x]++;
            mx=max(mx,x);}
        if(m[0]&1)
            return {};
        else
        {
          for(int i=0;i<m[0]/2;i++)
              ans.push_back(0);
        }
        for(int i=1;i<=mx/2;i++)
        {
            int curr=m[i],req=2*i;
            if(curr>m[req])
                return {};

            for(int j=0;j<curr;j++)
            {
                ans.push_back(i);
            }
            m[req]-=curr;
        }
    
        if(ans.size()!=a.size()/2)
            return {};
        return ans;
    }
};