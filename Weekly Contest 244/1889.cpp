class Solution {
public:
    int minWastedSpace(vector<int>& pac, vector<vector<int>>& box) {
        sort(pac.begin(),pac.end());
        int n=pac.size(),m=box.size();
        for(int i=0;i<m;i++)
        {
          sort(box[i].begin(),box[i].end());  
        }
       
       
       long long sum=accumulate(pac.begin(),pac.end(),0ll);
        long long ans=1e15;
        
        for(int i=0;i<m;i++)
        {
            if(box[i].back()>=pac.back()){
                long long prev=0,cnt=0;
                
                for(int j=0;j<box[i].size();j++)
                {
                   auto it=upper_bound(pac.begin()+prev,pac.end(),box[i][j])-pac.begin();
                 cnt+=box[i][j]*(it-prev);
                    prev=it;
                    
                }
                ans=min(ans,cnt-sum);
            }
        }
        if(ans==1e15)
            return -1;
        return ans%1000000007;
    }
};






