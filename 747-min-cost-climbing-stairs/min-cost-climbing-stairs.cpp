class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> sumCost(n, 0);
        sumCost[0] = 0;
        sumCost[1] = 0;

        for (int i = 2; i < n; i++) {

            sumCost[i] =
                min(sumCost[i - 1] + cost[i - 1], sumCost[i - 2] + cost[i - 2]);
        }
        return min(sumCost[n - 1] + cost[n - 1], sumCost[n - 2] + cost[n - 2]);
    }
};