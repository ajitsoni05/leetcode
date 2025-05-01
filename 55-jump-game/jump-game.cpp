class Solution {
public:
    void canJumpFrom(vector<int>&nums,int idx ,bool& ans,vector<int>&mem){
        if(idx>nums.size())return;
        if(idx==nums.size()-1){
            ans = true;
            return;
        }
        int max_j = nums[idx];
        if(mem[idx]==0)return;

        for(int i=1;i<=max_j;i++){
            canJumpFrom(nums,idx+i,ans,mem);
            if(ans){
                mem[idx]=1;
                return;
            }
        }
        mem[idx]=0;
    }
    bool canJump(vector<int>& nums) {
        bool ans = false;
        vector<int> mem(nums.size(),-1);
        canJumpFrom(nums,0,ans,mem);
        return ans;
    }
};