class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>v,a;
        int cnt=0;
        for(auto &u:nums)
        {
            if(u<pivot)
                v.push_back(u);
            else if(u==pivot)
                cnt++;
            else
            {
                a.push_back(u);
            }
        }
        while(cnt--)
        {
            v.push_back(pivot);
        }
        for(auto &u:a)
        {
            v.push_back(u);
        }
        return v;
    }
};