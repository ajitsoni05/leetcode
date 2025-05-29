class Solution {
public:
    void allXor(vector<int>&nums,int curXor,int&sum,int idx){
        if(idx == nums.size()){
            sum+=curXor;
            return ;
        }
        allXor(nums,curXor^nums[idx],sum,idx+1);
        allXor(nums,curXor,sum,idx+1);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        allXor(nums,0,ans,0);
        return ans;
    }
};