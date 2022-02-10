class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int>v(n);
        v[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            v[i]=v[i-1]^arr[i];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j;k<n;k++)
                {
                    int u1=v[j-1];
                    if(i!=0)
                        u1=u1^v[i-1];
                    int u2=v[k]^v[j-1];
                    
                    if(u1==u2){
                        // cout<<i<<j<<k<<" ";
                        ans++;}
                    
                }
            }
        }
        return ans;
    }
};