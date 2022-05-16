class Solution {
public:
    int largestCombination(vector<int>& candi) {
        int cnt[31];
        memset(cnt,0,sizeof(cnt));
        for(auto &c:candi){
            for(int i=30;i>=0;i--){
                if((1<<i)&c)cnt[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<31;i++){
            ans=max(ans,cnt[i]);
        }
        return ans;
    }
};