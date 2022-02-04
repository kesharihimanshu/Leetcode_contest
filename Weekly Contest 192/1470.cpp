class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int k=0,j=n;
        vector<int>ans(2*n);
        for(int i=0;i<2*n;i+=2)
        {
            ans[i]=nums[k];
            ans[i+1]=nums[j];
            k++;j++;
        }
        return ans;
    }
};