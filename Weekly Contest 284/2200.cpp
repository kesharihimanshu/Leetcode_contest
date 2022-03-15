class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        unordered_map<int,int>v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key)
                v[i]++;
        }
        for(int i=0;i<nums.size();i++){
            if(v.count(i))
                ans.push_back(i);
            else{
                for(auto it:v){
                    // cout<<it.first<<" ";
                    int u=abs(it.first-i);
                    if(u<=k){
                        
                        ans.push_back(i);
                    break;}
                }
            }
        }
        return ans;
    }
};