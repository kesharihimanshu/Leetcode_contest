class Solution {
public:
    double calculateTax(vector<vector<int>>& b, int in) {
        double ans=0;
        int u=0;
        int y=0;
        for(auto it:b){
           if(in>=it[0]){
               int y=it[0]-u;
              
               ans+=(double)((y*it[1])/100.0);
               u=it[0];
           }
            else{
               int y=in-u;
               
                   ans+=(double)((y*it[1])/100.0);
               u=it[0];
                return ans;
            }
        }
        return ans;
    }
};