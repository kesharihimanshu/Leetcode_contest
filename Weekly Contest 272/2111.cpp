class Solution {
public:
    //longest Non-decresing subsequence
    int LIS(vector<int>v)
    {
        vector<int>a;
        a.push_back(v[0]);
        for(int i=1;i<v.size();i++)
        {
            if(a.back()<=v[i])
                a.push_back(v[i]);
            else
            {
                auto it=upper_bound(a.begin(),a.end(),v[i])-a.begin();
                a[it]=v[i];
                
            }
        }
        return (v.size()-a.size());
    }
    int kIncreasing(vector<int>& arr, int k) {
        int ans=0;
        for(int i=0;i<k;i++)
        {
            vector<int>temp;
            for(int j=i;j<arr.size();j=j+k)
            {
                temp.push_back(arr[j]);
            }
            
            ans+=LIS(temp);
           
        }
        return ans;
    }
};