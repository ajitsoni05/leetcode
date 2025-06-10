
class Solution {
private:
    unordered_map<int, int> points;
    unordered_map<int, int> cache;

    int maxPoints(int num) {
        // Base cases
        if (num == 0) return 0;
        if (num == 1) return points.count(1) ? points[1] : 0;

        if (cache.count(num)) return cache[num];

        int gain = points.count(num) ? points[num] : 0;
        cache[num] = max(maxPoints(num - 1), maxPoints(num - 2) + gain);
        return cache[num];
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber = 0;

        // Precompute total points for each number
        for (int num : nums) {
            points[num] += num;
            maxNumber = max(maxNumber, num);
        }

        return maxPoints(maxNumber);
    }
};
