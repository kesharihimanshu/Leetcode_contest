class Cashier {
public:
    map<int,int>mp;
    int r,dis;
    int cnt=0;
    Cashier(int n, int discount, vector<int>& p, vector<int>& pr) {
        r=n;
        dis=discount;
        for(int i=0;i<p.size();i++)
        {
           mp[p[i]]=pr[i]; 
        }
    }
    
    double getBill(vector<int> p, vector<int> amount) {
        double ans=0.0;
        cnt++;
        for(int i=0;i<p.size();i++)
        {
           ans+=(mp[p[i]]*amount[i]); 
        }
        if(cnt%r==0)
        {
            ans=ans*((100-dis))/100;
        }
        return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */