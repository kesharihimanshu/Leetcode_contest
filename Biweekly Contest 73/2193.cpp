class Solution {
public:
    bool ispali(string s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i])
                return false;
        }
        return true;
    }
    int minMovesToMakePalindrome(string s) {
        if(s.size()==0)
            return 0;
        if(ispali(s)){
            return 0;
        }
        vector<int>f(26,0);
        for(int i=0;i<s.size();i++){
            f[s[i]-'a']=i;
        }
        int cnt=0;
        if(f[s[0]-'a']==0){
             cnt=s.size()/2;
            s.erase(s.begin()+0);
        }
        else{
            int u=f[s[0]-'a'];
            cnt=s.size()-1-u;
            s.erase(s.begin()+u);
            s.erase(s.begin()+0);
        }
        return cnt+minMovesToMakePalindrome(s);
        
    }
};