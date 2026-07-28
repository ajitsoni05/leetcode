class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxxProfit = 0;

        int minm = INT_MAX;

        for(int i = 0; i < prices.size(); i++){
            if(minm == INT_MAX)minm = prices[i];
            else{
                maxxProfit = max(maxxProfit, prices[i] - minm);
                minm = min(minm,prices[i]);
            }
        }

        return maxxProfit;
    }
};