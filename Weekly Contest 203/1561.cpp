

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int i=0,j=piles.size()-1,sum=0;
        int n=piles.size()-1;
        while(i<=j)
        {
            i++;
            if(i>=n)
                return sum;
            sum+=piles[i];
            i++;
            j--;
        }
        return sum;
    }
};


























