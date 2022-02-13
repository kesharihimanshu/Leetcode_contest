class Solution {
public:
    long long minimumRemoval(vector<int>& b) {
        long long ans=1e17,sum=0;
        for(int i=0;i<b.size();i++)
            sum+=b[i];
        sort(b.begin(),b.end());
        int n=b.size();
        for(int i=0;i<b.size();i++)
        {
            long long h=sum-(long long)(n-i)*b[i];
            ans=min(ans,h);
        }
        return ans;
    }
};