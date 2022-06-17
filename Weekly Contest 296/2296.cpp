class TextEditor {
public:
    stack<char>left,right;
    TextEditor() {
        
    }
    string s;
    int id=0;
    void addText(string text) {
       for(auto c:text)
           left.push(c);
    }
    
    int deleteText(int k) {
       int cnt=0;
    while(!left.empty() && k>0){
        left.pop();
        k--;
        cnt++;
    }
        return cnt;
    }
    
    string cursorLeft(int k) {
        
        while(!left.empty() && k>0){
            k--;
            right.push(left.top());
            left.pop();
        }
        
        return solve();
    }
    
    string cursorRight(int k) {
        while(!right.empty() && k>0){
            k--;
            left.push(right.top());
            right.pop();
        }
        return solve();
        
    }
    string solve(){
        int cnt=10;
        string s;
    while(!left.empty() && cnt>0){
        s.push_back(left.top());
        left.pop();
        cnt--;
    }
        reverse(s.begin(),s.end());
        for(auto c:s)
            left.push(c);
        return s;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */