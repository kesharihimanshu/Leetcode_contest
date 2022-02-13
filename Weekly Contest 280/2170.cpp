class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>m1,m2;
        int n=nums.size();
        if(n==1)
            return 0;
        if(n==2)
        {
            if(nums[0]==nums[1])
                return 1;
            return 0;
        }
        if(n==3)
        {
            if(nums[0]==nums[2])
            {
                if(nums[1]==nums[0])
                    return 1;
                return 0;
            }
            else
            {
                return 1;
            }
        }
        for(int i=0;i<n;i++)
        {
         if(i%2==0)
         {
             m1[nums[i]]++;
         }
            else
            {
                m2[nums[i]]++;
            }
        }
        int mx1=0,mx2=0,a=-1,b=-1;
        for(auto it:m1)
        {
            if(mx1<=it.second)
            {
             mx2=mx1;
                b=a;
                a=it.first;
                mx1=it.second;
            }
            else if(mx2<it.second)
            {
                b=it.first;
                mx2=it.second;
            }
        }
        int mx3=0,mx4=0,a1=-1,b1=-1;
          for(auto it:m2)
        {
            if(mx3<=it.second)
            {
             mx4=mx3;
                b1=a1;
                a1=it.first;
                mx3=it.second;
            }
            else if(mx4<it.second)
            {
                b1=it.first;
                mx4=it.second;
            }
        }
        int w1=(n+1)/2;
        int w2=n-w1,ans=0;
        if(a!=a1)
        {
            ans+=w1-mx1;
            ans+=w2-mx3;
            // cout<<ans<<" ";
        }
        else
        {
            int ans1=0,ans2=0;
            ans1+=w1-mx1;
            ans1+=w2-mx4;
            ans2+=w1-mx2;
            ans2+=w2-mx3;
            // cout<<mx1<<" "<<mx2<<" ";
            // cout<<mx3<<" "<<mx4<<" ";
            // cout<<w1<<" "<<w2<<" ";
            // cout<<ans1<<" "<<ans2;
            ans=min(ans1,ans2);
        }
           return ans;
        
    }
};