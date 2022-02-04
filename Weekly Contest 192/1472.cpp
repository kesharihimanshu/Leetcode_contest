class BrowserHistory {
public:
    vector <string> table;
    int cur;
    int size;
    int total;
    BrowserHistory(string homepage) {
        cur = 0;
        size = 1;
        total = 1;
        table.push_back(homepage);
    }
    
    void visit(string url) {
        if (cur == total - 1) {
            table.push_back(url);
            ++size;
            ++cur;
            ++total;
        } else {
            ++cur;
            size = cur + 1;
            table[cur] = url;
        }
    }
    
     string back(int steps) {
        string ret;
        if (steps > cur) {
            cur = 0;
        } else {
            cur = cur - steps;
        }
        ret = table[cur];
        return ret;
    }

    string forward(int steps) {
        string ret;
        if (cur + steps >= size) {
            cur = size - 1;
        } else {
            cur += steps;
        }
        ret = table[cur];
        return ret;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

