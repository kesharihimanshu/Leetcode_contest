class CustomStack {
public:
    vector<int>v;
    int n;
    CustomStack(int m) {
       n=m; 
    }
    
    void push(int x) {
        if(n>v.size())
        v.push_back(x);
    }
    
    int pop() {
        if(v.size()==0)
            return -1;
        int u=v.back();
        v.pop_back();
        return u;
    }
    
    void increment(int k, int val) {
        int b=min((int)v.size(),k);
      for(int i=0;i<b;i++)
      {
          v[i]+=val;
      }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */