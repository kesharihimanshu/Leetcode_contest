class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int>left;
         priority_queue<int ,vector<int>,greater<int>>right;
        long long temp[nums.size()];
        long long sum=0;
        int n=nums.size()/3;
        for(int i=nums.size()-1;i>=n;i--)
        {
            sum+=nums[i];
            right.push(nums[i]);
            if(right.size()>n)
            {
               sum-=right.top();
                right.pop();
                 
            }
          if(right.size()==n)
          {
              temp[i]=sum;
          }
           
        }
        sum=0;
        long long ans=1e18;
        for(int i=0;i<nums.size()-n;i++)
        { 
           sum+=nums[i];
            left.push(nums[i]);
            if(left.size()>n)
            {
                sum-=left.top();
                left.pop();
               
            }
            if(left.size()==n)
                 ans=min(ans,sum-temp[i+1]);
            
            
        }
        return ans;
    }
};

 