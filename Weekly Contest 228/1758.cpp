class Solution {
public:
    int minOperations(string s) {
        int ans1=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0)
            {
                if(s[i]=='0')
                    ans1++;
            }
            else{
                if(s[i]=='1')
                    ans1++;
            }
        }
        int ans2=0;
         for(int i=0;i<s.size();i++){
            if(i%2==1)
            {
                if(s[i]=='0')
                    ans2++;
            }
            else{
                if(s[i]=='1')
                    ans2++;
            }
        }
        return min(ans1,ans2);
    }
};