class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int j=0;
        int sum=0,ans=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(i-j+1==k){
                int avg=sum/k;
                if(avg>=t)
                    ans++;
                sum-=arr[j];
                j++;
            }
        }
        return ans;
    }
};