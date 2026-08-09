class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {

        int n = nums.size();
        vector<unordered_map<int, int>> IndexCommonDifferenceMap(n);

        int maxm = 1;

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {

                int c_d = nums[i] - nums[j];

                if (IndexCommonDifferenceMap[j].count(c_d)) {
                    IndexCommonDifferenceMap[i][c_d] =
                        max(IndexCommonDifferenceMap[j][c_d] + 1,
                            IndexCommonDifferenceMap[i][c_d]);
                } else {
                    IndexCommonDifferenceMap[i][c_d] = max(2,IndexCommonDifferenceMap[i][c_d]);
                }

                maxm = max(maxm, IndexCommonDifferenceMap[i][c_d]);
            }
        }

        return maxm;
    }
};