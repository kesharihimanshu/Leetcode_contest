class Solution {
public:
    #define ll long long 
    vector<long long> kthPalindrome(vector<int>& queries, int len) {
        vector<ll>ans;
        ll start=len%2==0?pow(10,len/2-1):pow(10,len/2);
        for(auto q:queries)
        {
            string s=to_string(start+q-1);
            string p=s;
            reverse(p.begin(),p.end());
            if(len%2==0)
            {
                s+=p;
            }
            else{
                s+=p.substr(1);
            }
            if(s.size()==len)
                ans.push_back(stoll(s));
            else
                ans.push_back(-1);
        }
        return ans;
    }
};