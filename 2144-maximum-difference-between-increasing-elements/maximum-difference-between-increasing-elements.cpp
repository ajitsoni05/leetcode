class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1;
        int least = INT_MAX;

        for(int i = 1; i < nums.size();i++){
            if(least > nums[i-1]){
                least = nums[i-1];
            }
            if(least != nums[i])
            maxDiff = max(maxDiff,nums[i]-least);

        }
        return maxDiff;
    }
};