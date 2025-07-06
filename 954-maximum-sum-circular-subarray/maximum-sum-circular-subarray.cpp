class Solution {
public:
    int maxNormalSum(vector<int>& nums) {
        int curMax = 0;
        int maxSum = nums[0];

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            curMax = max(nums[i], curMax + nums[i]);

            maxSum = max(maxSum, curMax);
        }

        return maxSum;
    }
    int specialSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixSum(n, 0);

        int curSum = 0;

        for (int i = 0; i < n; i++) {
            curSum += nums[i];
            prefixSum[i] = curSum;
        }

        vector<int> suffixSum(n, 0);

        curSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            curSum += nums[i];
            suffixSum[i] = curSum;
        }

        vector<int> rightMax(n, INT_MIN);
        int rightMaxSum = suffixSum[n - 1];

        for (int i = n - 1; i >= 0; i--) {
            rightMaxSum = max(rightMaxSum, suffixSum[i]);
            rightMax[i] = rightMaxSum;
        }

        int maxSpecialSum = 0;

        for (int i = 0; i < n - 1; i++) {
            maxSpecialSum = max(maxSpecialSum, prefixSum[i] + rightMax[i + 1]);
        }

        return maxSpecialSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int normalMax = maxNormalSum(nums);


        bool allNegative = true;
        for (int num : nums) {
            if (num > 0) {
                allNegative = false;
                break;
            }
        }
        if (allNegative)
            return normalMax;

        return max(normalMax, specialSum(nums));
    }
};