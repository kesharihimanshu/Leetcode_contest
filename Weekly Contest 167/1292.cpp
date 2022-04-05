class Solution {
public:
    int p[301][301];
    bool solve(int mid,vector<vector<int>>& mat,int th)
    {
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<=n-mid;i++)
        {
            for(int j=0;j<=m-mid;j++)
            {
                int sum=0;
                for(int k=i;k<i+mid;k++)
                {
                    if(j==0)
                        sum+=p[k][j+mid-1];
                    else
                        sum+=p[k][j+mid-1]-p[k][j-1];
                }
                if(sum<=th)
                    return true;
            }
        }
        return false;
        
    }
    void prefix(vector<vector<int>>& mat)
    {
        for(int i=0;i<mat[0].size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
                if(i==0)
                    p[j][i]=mat[j][i];
                else
                p[j][i]=p[j][i-1]+mat[j][i];
            }
        }
    }
    
    int maxSideLength(vector<vector<int>>& mat, int th) {
        int n=mat.size(),m=mat[0].size();
        memset(p,0,sizeof(p));
        prefix(mat);
        int low=0,high=min(m,n),ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(solve(mid,mat,th))
            {
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};