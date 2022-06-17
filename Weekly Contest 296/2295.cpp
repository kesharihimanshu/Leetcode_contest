class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& o) {
       unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        for(auto i:o){
            int id=m[i[0]];
            nums[id]=i[1];
            m[i[1]]=id;
        }
        return nums;
    }
};