class Solution {
public:
    vector<vector<int>> memo;
    vector<int> money;
    int target;

    int dp(int idx, int amt) {
        if (amt == target) return 0;
        if (idx == money.size()) return INT_MAX;

        if (memo[idx][amt] != -1) return memo[idx][amt];

        int numCoins = INT_MAX;
        for (int i = idx; i < money.size(); i++) {
            if (money[i] <= target - amt) { 
                int take = dp(i, amt + money[i]);
                if (take != INT_MAX) {
                    numCoins = min(numCoins, 1 + take);
                }
            }
        }

        return memo[idx][amt] = numCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memo.resize(n, vector<int>(amount + 1, -1));
        money = coins;
        target = amount;

        int res = dp(0, 0);
        return res == INT_MAX ? -1 : res;
    }
};
