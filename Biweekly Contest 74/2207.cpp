class Solution {
public:
    long long maximumSubsequenceCount(string text, string pat) {
     long long ans=0,a=0,b=0;
        for(auto &c:text)
        {
            if(c==pat[1])
            {
                ans+=a;
                b++;
            }
            if(c==pat[0])
                a++;
        }
        return ans+max(a,b);
    }
};