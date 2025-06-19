class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        int i = 0;

        while (i < n) {
            int minVal = nums[i];
            count++;

            auto it = lower_bound(nums.begin() + i, nums.end(), minVal + k + 1);

            i = it - nums.begin();
        }

        return count;
    }
};
