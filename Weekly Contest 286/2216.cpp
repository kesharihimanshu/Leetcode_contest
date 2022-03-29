class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans=0,cnt=0;
        int n=nums.size();
        if(n==1)
            return 1;
        if(n==2)
        {
            if(nums[0]==nums[1])
                return 2;
            return 0;
        }
        int i=1;
   
        while(i<nums.size())
        {
            if(nums[i]!=nums[i-1])
            {
             
                i+=2;
            }
            else{
                ans++;
                i++;
            }
        }
        if(i==n)
            ans++;
        return ans;
    }
};