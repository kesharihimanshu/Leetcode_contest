class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
       vector<unordered_set<string>>v(26);
        for(auto &i:ideas)
            v[i[0]-'a'].insert(i.substr(1));
        
        long long ans=0;
        for(int i=0;i<26;i++){
          
            for(int j=i+1;j<26;j++){
                int n1=v[i].size();
                int n2=v[j].size();
            for(auto &e:v[j]){
                if(v[i].find(e)==v[i].end())continue;
                n1--;
                n2--;
            }
                ans+=(long long)n1*n2*2;
            }
        }
        return ans;
      
		
    }
};