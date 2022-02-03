class Solution {
public:
    int par[101];// For parent 
    int n1;// It is equal to the number of vertex.
    static bool com(vector<int>a,vector<int>b)
    {
      return a[2]<b[2];  
    }
    int find(int n)
    {
        if(par[n]==n)
            return n;
        return par[n]=find(par[n]);
    }
    int mst(vector<vector<int>>& ed,vector<int>ex,vector<int>in)
    {
        int x=0;
        if(in.size())// If that edge must be included.
        {
            par[in[0]]=in[1];
            x+=in[2];
        }
        for(auto &e:ed)
        {
            if(e==ex)
                continue;
            int a=find(e[0]);
            int b=find(e[1]);
            if(a!=b)// If both component have different parent.
            {
               par[a]=b;
                x+=e[2];
            }
        }
        int no_of_par=0;     // if MST is not found(i.e. no of parents are more than 1) 
        for(int i=0;i<n1;i++)if(i==par[i])no_of_par++;
        return no_of_par>1?INT_MAX:x;
        return x;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& ed) {
        for(int i=0;i<ed.size();i++)
        {
            ed[i].push_back(i);
            
        }
        n1=n;
        sort(ed.begin(),ed.end(),com);
        vector<int>t;
        for(int i=0;i<n;i++)
                par[i]=i;
        int mn=mst(ed,t,t);// Find the MST value 
        vector<int>cri,p;
        for(auto &e:ed)
        {
            for(int i=0;i<n;i++)
                par[i]=i;
            int u=mst(ed,e,t);
            // If we exclude the egde and find out the mst if it is greater than mn so it is critical edge. 
            if(u>mn)
            {
                cri.push_back(e[3]);
            }
            else
            {
                for(int i=0;i<n;i++)
                par[i]=i;
                u=mst(ed,t,e);
                // If after including is than we again found the same value so it may exist in some MST and not present in some MST so it is a psedo-cricital edge.
                if(u==mn)
                    p.push_back(e[3]);
            }
        }
        return {cri,p};
        
    }
};








