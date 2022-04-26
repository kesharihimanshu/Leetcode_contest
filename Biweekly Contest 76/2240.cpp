class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
        
        while(total>=0){
           int cnt=total/cost2;
            ans+=cnt+1;
             total-=cost1;
        }
        return ans;
    }
};