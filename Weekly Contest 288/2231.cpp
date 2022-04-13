class Solution {
public:
    int largestInteger(int num) {
        vector<int>odd;
        vector<int>even;
        int u=num;
        while(u)
        {
            if(u%2)
                odd.push_back(u%10);
            else
                even.push_back(u%10);
            u=u/10;
        }
        string p=to_string(num);
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        int ans=0;
        for(int i=0;i<p.size();i++)
        {
            if((p[i]-'0')%2)
            {
                ans=ans*10+odd.back();
                odd.pop_back();
            }else{
                ans=ans*10+even.back();
                even.pop_back();
            }
        }
        return ans;
    }
};