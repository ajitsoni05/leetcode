class Solution {
public:
    int upper_bound_index(const vector<int>& nums, int left, int right, int value) {
    int low = left, high = right;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= value) {
            low = mid + 1;  // Move right if mid is ≤ value
        } else {
            high = mid;     // Possible candidate
        }
    }
    return low;  // First index where nums[i] > value
}

    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int sz = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < sz && diff != 0; ++i) {
            for (int j = i + 1; j < sz - 1; ++j) {
                int complement = target - nums[i] - nums[j];
             int hi = upper_bound_index(nums, j + 1, sz, complement), lo = hi - 1;
                if (hi < sz && abs(complement - nums[hi]) < abs(diff)) {
                    diff = complement - nums[hi];
                }
                if (lo > j && abs(complement - nums[lo]) < abs(diff)) {
                    diff = complement - nums[lo];
                }
            }
        }
        return target - diff;
    }
};
