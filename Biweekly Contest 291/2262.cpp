class Solution {
public:
    long long appealSum(string s) {
        unordered_map<char,int>m;
       long long int ans=0,cur=0;
        for(int i=0;i<s.size();i++){
             cur+=i+1-m[s[i]];
            ans+=cur;
            m[s[i]]=i+1;
        }
        return ans;
    }
};