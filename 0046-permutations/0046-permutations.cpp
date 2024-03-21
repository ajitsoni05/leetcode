class Solution {
public:
    void perm(vector<vector<int>>&permutations,int idx,vector<int>&nums,vector<int>temp){
        if(idx==nums.size()){
            permutations.push_back(temp);
            return;
        }
       for(int i=idx;i<nums.size();i++){
           swap(nums[idx],nums[i]);
           temp.push_back(nums[idx]);
           perm(permutations,idx+1,nums,temp);
           swap(nums[idx],nums[i]);
           temp.pop_back();
       }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>permutations;
        perm(permutations,0,nums,{});
        return permutations;
        
    }
};