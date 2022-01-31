class Solution {
public:
    int par[20004];// for parents
    int rank[20004];// size of connected components
  
    int find(int n)// standard find function
    {
        if(par[n]==n)
            return n;
        return par[n]=find(par[n]);
    }
    void merge(int a,int b )// standard union
    {
        a=find(a);
        b=find(b);
      if(a!=b)
      {
          par[a]=b;
          rank[b]+=rank[a];
      }
        
    }
    vector<int> groupStrings(vector<string>& w) {
        int n=w.size();
        for(int i=0;i<n;i++)// inisialization of par and rank
        {
            par[i]=i;
            rank[i]=1;
        }
       map<int,int>m;
       
        for(int i=0;i<w.size();i++)
        {
            int h=0;
            for(auto &c:w[i])
            {
                h|=(1<<(c-'a'));// bitmark of string
            }
            for(int j=0;j<26;j++)
            {
                if(h & (1<<j))// if that char present in our string
                {
                    int del=h^(1<<j);// after removing the particular char
                    if(m.count(del))// if after deletion a string that connect to another
                        merge(m[del],i);
                    for(int k=0;k<26;k++)// after replacment
                    {
                        int rep=del|(1<<k);
                        if(rep!=del && m.count(rep))
                            merge(m[rep],i);
                    }
                }
                else{                 // after adding a char
                    int add=h|(1<<j);
                    if(m.count(add))
                        merge(m[add],i);
                }
            }
            m[h]=i;// inserting into our map
        }
        int ans=0,mx=0;
       for(int i=0;i<n;i++)
       {
           if(par[i]==i)
           {
               
               ans++;// number of components 
               mx=max(mx,(int)rank[i]);// max size component
           }
       }
       
        return {ans,mx};
    }
};