class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int m=arr[(n-1)/2];
        vector<int>ans;
        int i=0,j=n-1;
        while(i<=j)
        {
            if(m-arr[i]>arr[j]-m)
            {
                ans.push_back(arr[i]);
                i++;
                k--;
            }
            else if(m-arr[i]<arr[j]-m)
            {
                ans.push_back(arr[j]);
                j--;
                k--; 
            }
            else
            {
                if(arr[i]>arr[j])
                {
                    ans.push_back(arr[i]);
                    i++;
                }
                else
                {
                    ans.push_back(arr[j]);
                    j--;
                }
                k--;
            }
            if(k==0)
                return ans;
        }
        return ans;
    }
};