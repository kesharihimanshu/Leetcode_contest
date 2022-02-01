class Solution {
public:
    char findKthBit(int n, int k) {
        vector<string>ans(n);
        ans[0]="0";;
        for(int i=1;i<n;i++)
        {
            string u=ans[i-1];
            u.push_back('1');
            string y=ans[i-1];
            reverse(y.begin(),y.end());
            for(auto &c:y)
            {
                if(c=='0')
                    u.push_back('1');
                else
                    u.push_back('0');
            }
            ans[i]=u;
            
        }
        return ans[n-1][k-1];
    }
};