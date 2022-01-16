#include<bits/stdc++.h>
using namespace std;
#define int long long
int inf=10000000000000;
signed main(){
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    int a[n];
    map<int,vector<int>>m;
    for(int i=0;i<n;i++){
    cin>>a[i];
    m[a[i]].push_back(i);}
    int ans=-1;
    for(auto it:m)
    {
        auto v=it.second;
        if(v.size()<2)
        continue;
        int a=v[0],b=v[1];
        for(int i=2;i<v.size();i++)
        {
            if(b-a>(v[i]-v[i-1]))
            {
                a=v[i-1];
                b=v
                [i];
            }
        }
        int temp=a+n-b;
        ans=max(ans,temp);
    }
    if(ans==-1)
    cout<<-1<<endl;
    else
    cout<<ans<<endl;
    
}
}