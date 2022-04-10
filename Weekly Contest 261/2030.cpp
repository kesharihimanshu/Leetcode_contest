class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int rep) {
        stack<char>st;
        int cnt=0;
        for(auto &c:s)
        {
            if(c==letter)
                cnt++;
        }
        int taken=0,used=0;
        int n=s.size();
        st.push(s[0]);
        if(s[0]==letter)
        {
            used++;
            taken++;
        }
       for(int i=1;i<s.size();i++)
       {
          
               while(!st.empty() && st.size()+n-i>k &&st.top()>s[i])
               {
                   if(st.top()==letter){
                       if(taken-1+cnt-used>=rep)
                       {
                           taken--;
                       }
                       else
                           break;
                   }
                   // cout<<st.top()<<" ";
                   st.pop();
               }
               if(s[i]==letter){
                   used++;
                   taken++;}
               st.push(s[i]);
               
               
           }
        while(st.size()>k)
        {
            if(st.top()==letter)
                taken--;
            st.pop();
        }
        // cout<<taken<<" ";
        for(int i=0;i<rep-taken;i++){
            if(st.top()==letter)
                taken--;
            st.pop();}
        for(int i=0;i<rep-taken;i++)
            st.push(letter);
        
        
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
       
    }
};