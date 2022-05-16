class Solution {
public:
    vector<string> removeAnagrams(vector<string>& w) {
        int n=w.size();
        int i=1;
        while(i<n){
            string a=w[i-1],b=w[i];
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            if(a==b){
                w.erase(w.begin()+i);
                n--;
            }
            else
                i++;
        }
        return w;
        
    }
};