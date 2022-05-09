class Solution {
public:
    string removeDigit(string n, char digit) {
        for(int i=0;i<n.size()-1;i++){
            if(n[i]==digit && n[i+1]>n[i])
                return n.substr(0,i)+n.substr(i+1);
        }
        int last=n.rfind(digit);
        return n.substr(0,last)+n.substr(last+1);
    }
};