class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1;
        int j=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]-nums[j]>k){
                ans++;
                j=i;
            }
            i++;
        }
        return ans;
        
    }
};