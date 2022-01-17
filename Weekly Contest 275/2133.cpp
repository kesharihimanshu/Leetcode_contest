class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            unordered_set<int>s,s1;
            int mn=101,mx=0;
            for(int j=0;j<n;j++)
            {
                s.insert(mat[i][j]);
                s1.insert(mat[j][i]);
                mn=min(mn,min(mat[i][j],mat[j][i]));
                mx=max(mx,max(mat[i][j],mat[j][i]));
                
            }
            if(mx==n && mn==1 && s.size()==n && s1.size()==n)
                int j;
            else
                return false;
        }
        return true;
    }
};