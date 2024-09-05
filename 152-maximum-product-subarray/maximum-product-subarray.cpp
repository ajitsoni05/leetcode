class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
            curMax, curMin
            if zero is encountered
            then curMax = 1 , curMin = 1
         */

        int res = *max_element(nums.begin(), nums.end());
        int max_ele = *max_element(nums.begin(), nums.end());
        int curMax = 1, curMin = 1;

        for (int i = 0; i < nums.size(); i++) {

            int temp = curMax * nums[i];
            curMax = max(nums[i] * curMin, max(nums[i] * curMax, nums[i]));
            curMin = min(temp, min(nums[i] * curMin, nums[i]));

            res = max(res, max(curMax, curMin));
        }
        return res;
    }
};