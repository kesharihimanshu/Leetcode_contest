class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans(n);
        int i=0,j=n-1;
        for(int k=0;k<n;k+=2)
        {
            ans[k]=nums[i];
            i++;
        }
       
        for(int k=1;k<n;k+=2)
        {
            ans[k]=nums[j];
            j--;
        }
        return ans;
    }
};