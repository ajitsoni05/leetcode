class Solution {
public:
    void fillup(vector<int>&nums,int idx,vector<vector<int>>&ans, vector<int>temp){
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
        
        //include
        temp.push_back(nums[idx]);
        fillup(nums,idx+1,ans,temp);
        temp.pop_back();
        
        //dont include
        fillup(nums,idx+1,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        fillup(nums,0,ans,{});
        return ans;
    }
};