class Solution {
public:
    int findFinalValue(vector<int>& nums, int ori) {
        map<int,int>m;
        for(auto &v:nums)
            m[v]++;
        while(1)
        {
            if(m[ori]>0)
            {
                ori*=2;
            }
            else
                return ori;
        }
        return ori;
        
    }
};