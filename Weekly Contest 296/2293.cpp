class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>num;
        num=nums;
        while(num.size()>1){
            vector<int>v;
            int m=0;
            for(int i=0;i<num.size();i+=2,m++){
                 if(m%2==0){
                     v.push_back(min(num[i],num[i+1]));
                 }
                else
                    v.push_back(max(num[i],num[i+1]));
            }
            num=v;
        }
        return num[0];
    }
};