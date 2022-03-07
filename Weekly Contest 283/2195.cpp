class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        nums.push_back(INT_MAX-7);
        sort(nums.begin(),nums.end());
        long long ans=0;
        long long cur=1;
        for(int i=0;i<nums.size()&& k>0;i++){
          int take=max((long long)0,min((long long)k,(long long)nums[i]-cur));
            ans+=(long long)(cur+take)*(cur+take-1)/2-(long long)(cur)*(cur-1)/2;
            k-=take;
            cur=nums[i]+1;
        }
 
        return ans;
    }
};