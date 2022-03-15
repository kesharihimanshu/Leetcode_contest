class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1){
            if(k%2==0)
                return nums[0];
            else
                return -1;
        }
        int mx=0;
        for(int i=0;i<n && i<k;i++){
            if(i==k-1)
                continue;
            mx=max(mx,nums[i]);
        }
        if(k<n)
            mx=max(mx,nums[k]);
        return mx;
        
    }
};