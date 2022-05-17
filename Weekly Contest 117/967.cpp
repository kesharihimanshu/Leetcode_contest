class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
          ans.push_back(i);
            
        }
        for(int i=2;i<=n;i++){
            vector<int>temp;
            for(auto &x:ans){
                int y=x%10;
                if(y+k<10)
                    temp.push_back(x*10+y+k);
                if(k>0 && y-k>=0){
                    temp.push_back(x*10+y-k);
                }
            }
            ans=temp;
        }
        return ans;
    }
};