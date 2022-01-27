class Solution {
public:
    bool solve(string a,string b)
    {
        int i=0,j=b.size()-1;
        while(i<j)
        {
            if(a[i]!=b[j])
                break;
            i++;
            j--;
        }
         if(i>=j)
            return true;
        string s=a.substr(i,j-i+1);
       
    string t=s;
        reverse(t.begin(),t.end());
        if(t==s)
            return true;
        s=b.substr(i,j-i+1);
         t=s;
        reverse(t.begin(),t.end());
        if(t==s)
            return true;
        return false;
        
    }
    bool checkPalindromeFormation(string a, string b) {
        return (solve(a,b)||solve(b,a));
    }
};