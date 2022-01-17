class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        vector<int>v(2*n);
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
            if(nums[i]==1)
                cnt++;
            
        }
        if(cnt==0||cnt==n)
        {
            return 0;
            
        }
        for(int i=0;i<2*n;i++){
            if(i!=0)
            {
                v[i]=v[i-1]+nums[i];
            }
            else
                v[i]=nums[i];
        }
        int j=0,ans=INT_MAX;
        for(int i=0;i<2*n;i++)
        {
           if(i-j+1==cnt)
           {
               int c=v[i]-v[j];
               if(nums[j]==1)
                   c++;
            
               ans=min(ans,cnt-c);
               j++;
           }
            
        }
        
        return ans;
        
    }
};