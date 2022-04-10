class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
       vector<int>cnt(3,0);
        for(auto &s:stones)
            cnt[s%3]++;
        if(cnt[0]%2==0)
            return cnt[1]>0 && cnt[2]>0;
        return abs(cnt[1]-cnt[2])>2;
        
    }
};