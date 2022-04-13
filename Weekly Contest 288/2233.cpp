class Solution {
public:
    int mod=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end());
         priority_queue<int,vector<int>,greater<int>>q;
        for(auto it:nums)
        {
            q.push(it);
        }
        // cout<<mx;
       while(k)
       {
           auto it=q.top();
           q.pop();
           q.push(it+1);
           k--;
       }
      long long ans=1; 
        while(!q.empty())
        {
            ans=(ans*q.top())%mod;
            q.pop();
        }
       
       
     
        return ans;
        
        
    }
};