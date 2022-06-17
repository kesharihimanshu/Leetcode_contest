class Solution {
public:
    int ans=INT_MAX;
    void solve(vector<int>& c, int k,vector<int>&len,int id){
        if(id>=c.size()){
            int x=0;
            for(int i=0;i<k;i++)
                x=max(x,len[i]);
            ans=min(ans,x);
            return;
        }
        for(int i=0;i<k;i++){
            len[i]+=c[id];
            solve(c,k,len,id+1);
            len[i]-=c[id];
        }
        return;
    }
    int distributeCookies(vector<int>& c, int k) {
  
        vector<int>len(k,0);
      
        for(int i=0;i<k;i++){
            
            len[i]+=c[0];
            
           solve(c,k,len,1);
            len[i]-=c[0];
        }
       
        return ans;
        
    }
};