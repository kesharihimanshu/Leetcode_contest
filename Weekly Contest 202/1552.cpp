class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int i=0,j=pos.back(),ans=0;
        while(i<=j)
        {
            long long mid=(i+j)/2;
            int x=0;
            int r=m;
            bool fl=false;
            while(r--)
            {
                auto it=lower_bound(pos.begin(),pos.end(),x);
                if(it==pos.end())
                {
                    fl=true;
                    break;
                }
                x=(*it)+mid;
            }
            if(fl==false)
            {
                ans=mid;
                i=mid+1;
            }
            else
                j=mid-1;
            
        }
        return ans;
    }
};