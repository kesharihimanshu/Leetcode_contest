#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
int t;
cin>>t;
while(t--)
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        vector<int>temp;
        for(int j=0;j<k;j++)
        {
            temp.push_back(x%2);
            x=x/2;

        }
        
        v.push_back(temp);
    }
   
    int ans=0;
    for(int i=0;i<k;i++)
    {
        int cnt=0;
       for(int j=0;j<n;j++)
       {
           if(v[j][i]==1)
           cnt++;
           else
           cnt--;
       }
       if(cnt>=0)
       ans+=(1<<i);
    }
    cout<<ans<<endl;

}

}