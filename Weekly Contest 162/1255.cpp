class Solution {
public:
    unordered_map<char,int>m;
    int solve(int id,vector<string>& w,vector<int>& sc){
        if(id>=w.size())
            return 0;
        int ans=0;
        for(int i=id;i<w.size();i++){
            int sum=0;
            bool fl=true;
            int j=0;
            for(;j<w[i].size();j++){
                if(m[w[i][j]]>0){
                    sum+=sc[w[i][j]-'a'];
                    m[w[i][j]]--;
                }
                else{
                    fl=false;
                    break;
                }
            }
            if(fl)
            {
                sum+=solve(i+1,w,sc);
                for(int k=0;k<w[i].size();k++)
                    m[w[i][k]]++;
            }
            else{
                sum=0;
                j--;
                while(j>=0){
                    m[w[i][j]]++;
                    j--;
                }
            }
            ans=max(ans,sum);
        }
        return ans;
    }
    int maxScoreWords(vector<string>& word, vector<char>& l, vector<int>& sc) {
        for(auto c:l)
            m[c]++;
        int ans=0;
        for(int i=0;i<word.size();i++){
            int sum=0;
            bool fl=true;
            int j=0;
            for(;j<word[i].size();j++){
                if(m[word[i][j]]>0){
                    sum+=sc[word[i][j]-'a'];
                    m[word[i][j]]--;
                }
                else{
                    fl=false;
                    break;
                }
            }
            if(fl)
            {
                sum+=solve(i+1,word,sc);
                for(int k=0;k<word[i].size();k++)
                    m[word[i][k]]++;
            }
            else{
                sum=0;
                j--;
                while(j>=0){
                    m[word[i][j]]++;
                    j--;
                }
            }
            // cout<<sum<<" ";
            ans=max(ans,sum);
        }
        return ans;
    }
};