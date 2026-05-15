class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0, j = 0;
        int n = nums.size();

        while (j < n) {

            int freq = 0;
            int val = nums[j];

            // count frequency safely
            while (j < n && nums[j] == val) {
                freq++;
                j++;
            }

            freq = min(freq, 2);

            // write allowed duplicates
            while (freq--) {
                nums[i++] = val;
            }
        }

        return i;
    }
};