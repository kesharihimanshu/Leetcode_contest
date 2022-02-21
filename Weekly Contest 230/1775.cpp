class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1=accumulate(nums1.begin(),nums1.end(),0);
         int sum2=accumulate(nums2.begin(),nums2.end(),0);
       if(nums1.size()>6*nums2.size()||nums1.size()*6<nums2.size())
           return -1;
        if(sum1>sum2)
        {
            return  minOperations(nums2,nums1);
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=nums2.size()-1,ans=0;
        while(sum1<sum2)
        {
            if(j<0 || i<nums1.size() && 6-nums1[i]>nums2[j]-1)
            {
                sum1+=6-nums1[i];
                i++;
            }
            else{
                sum2-=nums2[j]-1;
                j--;
            }
            ans++;
        }
        return ans;
        
        
    }
};