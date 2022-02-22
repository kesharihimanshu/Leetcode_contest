class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>a(n);
            vector<int>b(n);
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && nums[s.top()]>=nums[i]){
                s.pop();
            }
            if(s.empty())
                a[i]=-1;
            else
                a[i]=s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--)
        {
          while(!s.empty() && nums[s.top()]>=nums[i]){
                s.pop();
            }
             if(s.empty())
                b[i]=n;
            else
                b[i]=s.top();
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int n1=a[i];
            int n2=b[i];
            // cout<<n1<<" "<<n2<<" ";
            if(n1+1<=k && k<=n2-1)
            {
                // cout<<nums[i]<<" ";
                ans=max(ans,nums[i]*(n2-n1-1));
            }
        }
        return ans;
        
    }
};