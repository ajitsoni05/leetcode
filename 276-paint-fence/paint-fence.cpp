class Solution {
public:
    int numWays(int n, int k) {
        // base cases
        if(n == 1)return k;
        else if(n == 2) return k*k;

        vector<int>dp(n+1,0);

        dp[1] = k;
        dp[2] = k*k;

        for(int i = 3; i <= n; i++){
            dp[i] = (k-1)*dp[i-1] + 1*(k-1)*dp[i-2];
        }
        return dp[n];
    }
};