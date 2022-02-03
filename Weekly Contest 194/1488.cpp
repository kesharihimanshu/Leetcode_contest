class Solution {
public:
    vector<int> avoidFlood(vector<int>& r) {
        set<int>st;// for checking whether a sunny day is present or not to drythe lake.
        int n=r.size();
        unordered_map<int,int>m;// last time when that lake was filled.
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
          if(r[i]==0)
          {
              st.insert(i);
              ans[i]=1;
          }
            else
            {
                if(m.find(r[i])!=m.end())// check the lake is fill or not
                {
                   
                  
                    if(st.empty())
                        return {};
                    auto it=st.upper_bound(m[r[i]]);
                    if(it==st.end())
                    {
                        return {};
                    }
                    int id=*it;
                    ans[id]=r[i];
                    ans[i]=-1;
                    st.erase(id);
                m[r[i]]=i;
                    
                }
                else
                {
                   
                    ans[i]=-1;
                    m[r[i]]=i;
                }
               
            }
        }
        return ans;
    }
};