class Solution {
public:
    void subsets(set<vector<int>>&ans,int idx,vector<int>&nums,vector<int>temp){
        if(idx==nums.size()){
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subsets(ans,idx+1,nums,temp);
        temp.pop_back();
        
        subsets(ans,idx+1,nums,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<vector<int>>finalans;
        subsets(ans,0,nums,{});
        for(auto it:ans){
            finalans.push_back(it);
        }
        return finalans;
    }
};