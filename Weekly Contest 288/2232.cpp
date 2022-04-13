class Solution {
public:
    string minimizeResult(string expr) {
        int id=0;
     for(int i=0;i<expr.size();i++)
     {
         if(expr[i]=='+'){
             id=i;
             break;
         }
             
     }
        long long ans=INT_MAX;
        string ans1;
        for(int i=0;i<id;i++)
        {
            for(int j=id+1;j<expr.size();j++)
            {
                long long x,y,z;
                if(expr.substr(0,i).size()==0)
                    x=1;
                else
                x=stoll(expr.substr(0,i));
                if(expr.substr(i,id-i).size()==0 ||expr.substr(id+1,j-id).size()==0)
                    continue;
                 y=stoll(expr.substr(i,id-i))+stoi(expr.substr(id+1,j-id));
                if(expr.substr(j+1).size()==0)
                 z=1;
                else
                 z=stoll(expr.substr(j+1));
                long long temp=x*y*z;
                if(temp<ans)
                {
                    ans=temp;
                    string s=expr;
                    s.insert(i,"(");
                    s.insert(j+2,")");
                    ans1=s;
                }
            }
        }
        return ans1;
    }
};