class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        st.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            int u=__gcd(st.top(),nums[i]);
            if(u>1){
                long long h=(long long)nums[i]*st.top()/u;
                st.pop();
                st.push(h);
               while(st.size()>1){
                   int u1=st.top();
                   st.pop();
                   int u2=st.top();
                   st.pop();
                   u=__gcd(u1,u2);
                   if(u>1){
                        h=(long long)u1*u2/u;
                st.push(h);
                   }
                   else{
                      
                       st.push(u2);
                        st.push(u1);
                       break;
                   }
                   
               }
            }
            else{
                st.push(nums[i]);
            }
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};