class Solution {
public:
    int dp(vector<vector<int>>&memo, vector<int>&nums,int left,int right){
        if(right-left<0)return 0;

        if(memo[left][right]>0)return memo[left][right];

        int max_coins=0;
        for(int i=left;i<=right;i++){
            int gain = nums[left-1]*nums[i]*nums[right+1];

            int remaining = dp(memo,nums,left,i-1)+dp(memo,nums,i+1,right);

            max_coins= max(max_coins,gain+remaining);
        }
        memo[left][right]=max_coins;
        return max_coins;
    }
    int maxCoins(vector<int>& nums) {
        
        // 0 to n-1 
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        
        vector<vector<int>>memo(nums.size(),vector<int>(nums.size(),0));

        return dp(memo,nums,1,nums.size()-2);


        
        return 0;
    }
};