class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int>a,b;
        a.push_back(0);
        b.push_back(0);
        int ans=abs(goal);
        int n=nums.size();
        for(int i=0;i<(n/2);i++)
        {
            int sz=a.size();
            for(int j=0;j<sz;j++)
            {
                a.push_back(a[j]+nums[i]);
            }
        }
         for(int i=(n/2);i<n;i++)
        {
            int sz=b.size();
            for(int j=0;j<sz;j++)
            {
                b.push_back(b[j]+nums[i]);
            }
        }
        set<int>st(b.begin(),b.end());
        for(auto &x:a)
        {
            int y=goal-x;
            auto it=st.lower_bound(y);
            if(it!=st.end())
            {
                ans=min(ans,abs(goal-(x+*it)));
            }
            if(it!=st.begin()){
            it--;
           ans=min(ans,abs(goal-(x+*it)));
            }
            
        }
        return ans;
        
        
    }
};