class Solution {
public:
    int numPoints(vector<vector<int>>& d, int r) {
        int n=d.size();
        int count=0;
        double d2r=3.14/180.00;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            double pa=d[i][0];
            double pb=d[i][1];
            for(int ang=0;ang<360;ang++)
            {
               double a=d[i][0]+(double)r*cos(ang*d2r);
            double b=d[i][1]+(double)r*sin(ang*d2r);
                count=0;
                for(int k=0;k<n;k++)
                {
                    double dis=sqrt(pow(a-d[k][0],2)+pow(b-d[k][1],2));
                    if(dis<=  (double)(r+0.01))
                        count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};








