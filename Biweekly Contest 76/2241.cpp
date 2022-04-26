class ATM {
public:
    ATM() {
        
    }
    unordered_map<long long,long long>m;
    void deposit(vector<int> b) {
        m[20]+=b[0];
        m[50]+=b[1];
        m[100]+=b[2];
        m[200]+=b[3];
        m[500]+=b[4];
        return;
    }
    
    vector<int> withdraw(int a) {
        vector<int>ans;
        long long u=a/500;
        ans.push_back(min(u,m[500]));
        a-=500*(min(u,m[500]));
         u=a/200;
        ans.push_back(min(u,m[200]));
        a-=200*(min(u,m[200]));
         u=a/100;
        ans.push_back(min(u,m[100]));
        a-=100*(min(u,m[100]));
         u=a/50;
        ans.push_back(min(u,m[50]));
        a-=50*(min(u,m[50]));
         u=a/20;
        ans.push_back(min(u,m[20]));
        a-=20*(min(u,m[20]));
        if(a!=0)
        {
            return {-1};
        }
        reverse(ans.begin(),ans.end());
        m[20]-=ans[0];
        m[50]-=ans[1];
        m[100]-=ans[2];
        m[200]-=ans[3];
        m[500]-=ans[4];
        return ans;
        
        
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */