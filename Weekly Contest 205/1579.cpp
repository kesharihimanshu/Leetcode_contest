class Solution {
public:
// FOR REMOVING AND ADDING THE EDGES WE JUST USE UNION FIND.

    static bool com(vector<int>&a,vector<int>&b)
    {
        return a[0]>b[0];
    }
    int find(int u,vector<int>&p)
    {
        if(p[u]==u)
            return u;
        return p[u]=find(p[u],p);
    }
    bool uni(int u,int v,vector<int>&rank,vector<int>&par)
    {
        u=find(u,par);
        v=find(v,par);
        if(u!=v)
        {
            if(rank[u]<rank[v])
            {
                par[u]=v;
            }
            else if(rank[u]>rank[v])
            {
                par[v]=u;
            }
            else
            {
                par[u]=v;
                rank[v]++;
            }
            return true;
        }
        return false;
        
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) {
        sort(e.begin(),e.end(),com);
        vector<int>ra(n+1);
          vector<int>rb(n+1);
          vector<int>pa(n+1);
          vector<int>pb(n+1);
        for(int i=0;i<=n;i++)
        {
          ra[i]=1;
            rb[i]=1;
            pa[i]=i;
            pb[i]=i;
        }
        int ma=1,mb=1,req=0;
        for(auto & it:e)
        {
            if(it[0]==3)
            {
                bool temp_a=uni(it[1],it[2],ra,pa);
                bool temp_b=uni(it[1],it[2],rb,pb);
                if(temp_a==true)
                    ma++;
                if(temp_b==true)
                    mb++;
                if(temp_a==false && temp_b==false)
                    req++;
            }
            else if(it[0]==1)
            {
                   bool temp_a=uni(it[1],it[2],ra,pa);
                 if(temp_a==true)
                    ma++;
               else
                    req++;
            }
            else
            {
                bool temp_b=uni(it[1],it[2],rb,pb);
                 if(temp_b==true)
                    mb++;
               else
                    req++;  
            }
        }
        
        if(ma!=n||mb!=n)
            return -1;
        return req;
        
    }
};








