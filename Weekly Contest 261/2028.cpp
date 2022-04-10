class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int total=(m+n)*mean;
        int sum=total-accumulate(rolls.begin(),rolls.end(),0);
        int mid=sum/n;
        if(mid<=0)
            return {};
        vector<int>ans;
        if(mid==6)
        {
            if(sum%n)
                return {};
            for(int i=0;i<n;i++)
                ans.push_back(6);
            return ans;
        }
        else if(mid>6)
            return {};
        else{
            if(sum%n)
            {
                for(int i=0;i<n;i++)
                {
                  ans.push_back(mid);  
                }
                for(int i=0;i<sum%n;i++)
                {
                    ans[i]++;
                }
                return ans;
            }
            else{
                for(int i=0;i<n;i++)
                    ans.push_back(mid);
                return ans;
            }
        }
        return {};
    }
};