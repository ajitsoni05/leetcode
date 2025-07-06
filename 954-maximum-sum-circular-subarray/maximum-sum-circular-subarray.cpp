class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = 0;
        int curMin = 0;
        int maxSum = nums[0];
        int minSum = nums[0];

        int totalSum = 0;

        int n = nums.size()
;
        for(int i = 0; i < n; i++){
            curMax = max(nums[i],curMax+ nums[i]);
            maxSum = max(maxSum,curMax);
            curMin = min(nums[i],curMin + nums[i]);
            minSum = min(minSum,curMin);
            totalSum += nums[i];
        }


        if(totalSum == minSum)return maxSum;
        else return max(maxSum,(totalSum - minSum));
        
    }
};