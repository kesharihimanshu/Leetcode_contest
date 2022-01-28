class ThroneInheritance {
public:
    map<string,int>s;
    map<int,string>m;
    vector<int>v[100005];// for adj matrix
    int t=0;
    int d[100005];
    ThroneInheritance(string kingName) {
        t++;
        m[t]=kingName;
        s[kingName]=t;
    }
    
    void birth(string parentName, string childName) {
        t++;
        m[t]=childName;
        s[childName]=t;
        v[s[parentName]].push_back(s[childName]);
        
    }
    
    void death(string name) {
        d[s[name]]=1;
        
    }
    vector<string>ans;
    void dfs(int n)
    {
      if(d[n]==0)
        ans.push_back(m[n]);
        for(auto &h:v[n])
        {
            dfs(h);
        }
    }
    
    vector<string> getInheritanceOrder() {
        ans.clear();
        dfs(1);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */