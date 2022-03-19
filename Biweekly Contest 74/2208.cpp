class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>q;
       long double sum=0;
        for(int i=0;i<nums.size();i++)
        {
            q.push((double)nums[i]);
            sum+=nums[i];
        }
        sum=(double)sum/2.0;
        int ans=0;
        while(!q.empty())
        {
            auto x=q.top();
            q.pop();
            x=(double)x/2.0;
            ans++;
            sum-=x;
            if(sum<=0)
                return ans;
            q.push(x);
            
        }
        return -1;
    }
};