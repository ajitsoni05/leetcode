class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxm=INT_MIN;
        for(int i=0;i<nums.size();i++)maxm=max(maxm,nums[i]);
        int sol= k*maxm+ (k-1)*(k)/2;
        return sol;
    }
};