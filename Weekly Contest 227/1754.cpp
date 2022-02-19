class Solution {
public:
    string largestMerge(string w1, string w2) {
        int n=w1.size(),m=w2.size();
        string s;
        int i=0,j=0;
        while(i<n||j<m)
        {
            if(i>=n)
            {
                s.push_back(w2[j]);
                    j++;
            }
            else if(j>=m)
            {
               s.push_back(w1[i]);
                    i++; 
            }
            else{
                if(w1[i]>w2[j])
                {
                   s.push_back(w1[i]);
                    i++;   
                }
                else if(w1[i]<w2[j])
                {
                   s.push_back(w2[j]);
                    j++; 
                }
                else
                {
                    if(w2.substr(j)>w1.substr(i))
                    {
                        s.push_back(w2[j]);
                    j++;
                    }
                    else
                    {
                         s.push_back(w1[i]);
                    i++;  
                    }
                }
            }
        }
        return s;
    }
};