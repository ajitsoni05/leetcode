class Solution {
public:

    void combinations(vector<int>& candidates,vector<vector<int>>&ans,int idx,vector<int>temp,int sum,int target){
        if(idx==candidates.size()){
            if(sum==target)ans.push_back(temp);
            return;
        }
        if(sum+candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            combinations(candidates,ans,idx,temp,sum+candidates[idx],target);
            temp.pop_back();
        }
        combinations(candidates,ans,idx+1,temp,sum,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>>ans;
        combinations(candidates,ans,0,{},0,target);
        return ans;
    }
};