  bool com(pair<int,int>a,pair<int,int>b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;
    }
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
       vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)
        {
            int newnum=0;
            int cur=nums[i];
                bool fl=false;
            for(int j=9;j>=0;j--)
            {
                int digit=cur/pow(10,j);
                if(!digit && !fl && j!=0)
                {
                    continue;
                }
                fl=true;
                newnum+=mapping[digit]*pow(10,j);
                cur-=digit*pow(10,j);
            }
            v.push_back({newnum,i});
        }
        sort(v.begin(),v.end(),com);
        vector<int>ans;
        for(auto c:v)
        {
            ans.push_back(nums[c.second]);
        }
        return ans;
        
    }
};