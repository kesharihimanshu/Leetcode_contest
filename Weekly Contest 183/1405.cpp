class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>q;
        if(a>0)
            q.push({a,'a'});
          if(b>0)
            q.push({b,'b'});
          if(c>0)
            q.push({c,'c'});
        int size=0;
        string ans="";
        while(!q.empty())
        {
            auto it=q.top();
            q.pop();
            if(size>1 && ans[size-1]==it.second && ans[size-2]==it.second)
            {
                if(q.empty())
                    return ans;
                auto pq=q.top();
                ans.push_back(pq.second);
                size++;
                q.pop();
                if(pq.first>1)
                    q.push({pq.first-1,pq.second});
                q.push({it.first,it.second});
            }
            else
            {
                ans.push_back(it.second);
                size++;
                  if(it.first>1)
                    q.push({it.first-1,it.second});
            }
        }
        return ans;
    }
};