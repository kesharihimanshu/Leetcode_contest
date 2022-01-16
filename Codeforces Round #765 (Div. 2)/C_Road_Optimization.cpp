#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a(502);
vector<int>b(502);
int dp[502][502];
 int n,m;
int solve(int pos,int k)
{
    if(pos>=n)
    return 0;
    if(dp[pos][k]!=-1)
    return dp[pos][k];
    int ans=1e9;
    for(int remove=0;remove<=k;remove++)
    {
       
        if(pos+remove>=n)
        break;
        int cost=(a[pos+remove+1]-a[pos])*b[pos];
    //    cout<<b[pos]<<" ";
        ans=min(ans,cost+solve(pos+remove+1,k-remove));

    }
   return  dp[pos][k]=ans;
    
}
signed main(){
int t=1;

while(t--)
{
a.clear();
b.clear();
   int k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    cin>>a[i];
     for(int i=0;i<n;i++){
   int y;
   cin>>y;
   b[i]=y;}
   
    
    a[n]=m;
    memset(dp,-1,sizeof(dp));
    int ans=solve(0,k);
    cout<<ans<<"\n";

}
}