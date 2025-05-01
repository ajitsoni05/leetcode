class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l_min = INT_MAX;
        int l_max = INT_MAX;

        int total =0;

        for(int i=0;i<prices.size();i++){
            if(prices[i]<l_max){
                total += l_max - l_min;

                l_min = prices[i];
                l_max = l_min;
            }else{
                l_max = prices[i];
            }
        }
        total += l_max - l_min;
        return total;
    }
};