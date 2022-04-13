class Solution {
public:
    #define ll long long
    long long maximumBeauty(vector<int>& fl, long long nf, int target, int full, int par) {
        sort(fl.begin(),fl.end());//sort the array.
        ll ans=0;
        ll n=fl.size();
        vector<long long>prefix(n);// for many flowers are required for reaching the a particular point.
        prefix[0]=fl[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+(ll)fl[i];
        }
        for(int i=n;i>=0;i--)
        {
            if(i==n){
                
            }
            else{
                ll req_full=max(0LL,(ll)target-fl[i]);
                if(req_full>nf)
                    break;
                nf-=req_full;
                fl.pop_back();
            }
            ll ans_full=((n-i)*full);
            ll ans_par=0;
            ll low=0,high=target-1;
            while(low<=high)
            {
                ll mid=(low+high)/2;
                ll idx=upper_bound(fl.begin(),fl.end(),mid)-fl.begin();
                if(idx==0)
                    low=mid+1;
                else{
                    ll have_fl=prefix[idx-1];
                    ll req_fl=mid*idx;
                    ll extra=req_fl-have_fl;
                    if(extra<=nf)
                    {
                        low=mid+1;
                        ans_par=par*mid;
                    }
                    else{
                        high=mid-1;
                    }
                }
            }
            ans=max(ans,ans_par+ans_full);
        }
        return ans;
    }
};