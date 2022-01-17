class Solution {
public:
    int minMoves(int target, int m) {
        int ans=0;
        while(target>1)
        {
            if(target&1)
            {
                target--;
                ans++;
            }
            else
            {
                if(m>0)
                {
                    ans++;
                    target=target/2;
                    m--;
                }
                else
                {
                    ans+=(target-1);
                    target=1;
                }
            }
        }
        return ans;
    }
};