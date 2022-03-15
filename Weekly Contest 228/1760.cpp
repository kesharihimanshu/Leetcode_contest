class Solution {
public:
    bool solve(int m,vector<int>& nums, int mx){
        for(auto &b:nums){
            if(b<=m)
                continue;
            int u=b/m;
            if(b%m)
                u++;
            u--;
            mx-=u;
            
            if(mx<0)
                return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int mx) {
        int a=0;
        for(auto &b:nums){
            a=max(a,b);
        }
        int i=1,j=a,ans=-1;
        while(i<=j){
            int m=(i+j)/2;
            if(solve(m,nums,mx))
            {
                ans=m;
                j=m-1;
            }
            else{
                i=m+1;
            }
        }
        return ans;
    }
};