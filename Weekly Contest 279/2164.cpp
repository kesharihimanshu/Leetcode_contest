class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>odd,even;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                even.push_back(nums[i]);
                
            }
            else
            {
                odd.push_back(nums[i]);
            }
        }
        sort(even.begin(),even.end());
        sort(odd.rbegin(),odd.rend());
        for(int i=0;i<nums.size();i=i+2)
        {
            nums[i]=even[i/2];
        }
         for(int i=1;i<nums.size();i=i+2)
        {
            nums[i]=odd[i/2];
        }
        return nums;
    }
};