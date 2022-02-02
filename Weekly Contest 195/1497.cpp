class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int>m;
        for(auto &a:arr)
        {
            int u=((a%k)+k)%k;
            m[u]++;
        }
        for(int i=0;i<k;i++)
        {
            if(i==0)
            {
                if(m[i]&1)
                    return false;
                
            }
            else
            {
                if(m[i]!=m[k-i])
                    return false;
            }
        }
        return true;
    }
};