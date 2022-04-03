class Encrypter {
public:
    unordered_map<char,string>m;
    unordered_map<string,int>cnt;
    Encrypter(vector<char>& keys, vector<string>& val, vector<string>& dic) {
        for(int i=0;i<keys.size();i++)
        {
            m[keys[i]]=val[i];
        }
        
        for(auto &y:dic)
        {
            string p=encrypt(y);
            cnt[p]++;
        }
        
    }
    
    string encrypt(string word1) {
        string a;
        for(auto w:word1)
        {
            a+=m[w];
        }
        return a;
    }
    
    int decrypt(string word2) {
        return cnt[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */