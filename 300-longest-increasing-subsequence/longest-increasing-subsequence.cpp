class Solution {
public:
    vector<int>memo;
    int n;
    vector<int>numbers;
    int dp(int i){
        if(i == n)return 0;

        if(memo[i]!=-1)return memo[i];

        int longest = 1;

        for(int index = i-1; index >= 0; index--){
           if(numbers[i] > numbers[index]){
            longest = max(longest,dp(index)+1);
           }
        }

        return memo[i] = longest;


    }
    int lengthOfLIS(vector<int>& nums) {
        // idx LIS at nums.len
        numbers = nums;
        n = nums.size();
        memo.resize(n,-1);
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp(i));  // compute LIS ending at i
        }

        return ans;
    }
};