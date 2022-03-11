class Solution {
public:
// Pure BFS Question.
    int minJumps(vector<int>& arr) {
         int n=arr.size();
        if(n==1)
            return 0;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        queue<int>q;
       
        vector<bool>vis(arr.size(),false);
        q.push(0);
        vis[0]=true;
        int move=0;
        while(!q.empty()){
            int sz=q.size();
             
            while(sz--){
                auto a=q.front();
                q.pop();
                if(a==n-1)
                    return move;
                for(auto t:m[arr[a]]){
                   
                    if(vis[t]==false){
                        q.push(t);
                        vis[t]=true;}
                }
                m[arr[a]].clear();
                if(a!=0)
                {
                  if(vis[a-1]==false){
                        q.push(a-1);
                        vis[a-1]=true;}  
                }
               
                    if(vis[a+1]==false){
                        q.push(a+1);
                        vis[a+1]=true;}
               
            }
             move++;
          
        }
        return 0;
    }
};