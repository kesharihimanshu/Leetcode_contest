class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int target) {
        for(int i=0;i<times.size();i++)
        {
            times[i].push_back(i);//to detect the index after sorting
        }
        sort(times.begin(),times.end());// sort according to the arrival time
        int n=times.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        // for again insert into the set when chair is free
       set<int>st;// set is used for unoccupied chair
        for(int i=0;i<=n;i++)
            st.insert(i);
        for(auto &v:times)
        {
            while(!q.empty() && q.top().first<=v[0])// if at the arrival if anyone wants to go then chair is free;
            {
                int x=q.top().second;
                st.insert(x);// change into the occupied chair to unoccupied 
                q.pop();
            }
            if(v[2]==target)
                return *st.begin();
            int y=*st.begin();
            st.erase(y);
            q.push({v[1],y});
        }
        return -1;
        
        
    }
};