class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int>q;// for maintaining the deque in incresing order
        int res=nums[0];
        // nums[i]->max val till ith elements.
        for(int i=0;i<nums.size();i++)
        {
            nums[i]+=q.size()?q.front():0;
            res=max(res,nums[i]);
            while(q.size()>0 && nums[i]>q.back())// maintain the incresing order
                q.pop_back();
            if(nums[i]>0)
                q.push_back(nums[i]);
            if(i>=k && q.size()>0 && nums[i-k]==q.front())
                q.pop_front();
        }
        return res;
    }
};