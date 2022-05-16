class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        bool fl=true;
        for(int i=2;i<num.size();i++){
            if(num[i]==num[i-1] && num[i]==num[i-2]){
                fl=false;
                if(ans.size()==0)
                {
                    for(int j=0;j<3;j++)
                    ans.push_back(num[i]);
                    
                }
                else{
                    if(ans[0]<num[i]){
                        ans="";
                           for(int j=0;j<3;j++)
                    ans.push_back(num[i]);
                    }
                }
            }
        }
        if(fl)return "";
        return ans;
    }
};