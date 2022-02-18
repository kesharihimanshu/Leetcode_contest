class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int carry=0;
        vector<int>ans;
        int i=arr1.size()-1,j=arr2.size()-1;
        while(i>=0||j>=0||carry)
        {
            if(i>=0)
            {
              carry+=arr1[i];
                i--;
            }
            if(j>=0)
            {
                carry+=arr2[j];
                j--;
            }
            ans.push_back(carry&1);
            carry=-(carry>>1);
        }
        while(ans.size()>1 && ans.back()==0)
            ans.pop_back();
        if(ans.size()==0)
            return {0};
        reverse(ans.begin(),ans.end());
        return ans;
    
    }
};