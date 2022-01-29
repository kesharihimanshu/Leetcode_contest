class Solution {
public:
    int cnt[100005];// count the number of island of a certain size
    int par[100005];// to find out the parent of a node
    int sz[100005];// size of the connected component
    int st[100005];// ith bit is set or not.
    int find(int n)
    {
        if(par[n]==n)
            return n;
        return par[n]=find(par[n]);
    }
    void merge(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x!=y)
        {
            cnt[sz[x]]--;
            cnt[sz[y]]--;
            par[x]=y;
            sz[y]+=sz[x];
            cnt[sz[y]]++;
        }
    }
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
        for(int i=1;i<=n;i++){
            par[i]=i;
            cnt[i]=0;
            sz[i]=1;}
        int ans=-1,step=1;
        for(auto &a:arr)
        {
            
            st[a]=1;
            cnt[1]++;
            if(st[a-1])
            {
                merge(a,a-1);
            }
            if(st[a+1])
                merge(a,a+1);
            if(cnt[m])
                ans=step;
            step++;
            
        }
        return ans;
    }
};